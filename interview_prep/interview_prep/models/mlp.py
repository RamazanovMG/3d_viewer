from __future__ import annotations

import numpy as np

from interview_prep.models.base import BaseModel, check_xy


class MLP(BaseModel):
    """One-hidden-layer net.

    task='regression' uses MSE; 'classification' is binary with sigmoid + BCE.
    dropout is train-time only. l2 is weight decay on W1/W2 (not biases).
    """

    def __init__(
        self,
        hidden: int = 16,
        dropout: float = 0.0,
        l2: float = 0.0,
        lr: float = 0.05,
        max_iter: int = 2000,
        task: str = "regression",
        random_state: int | None = 0,
    ) -> None:
        if not 0.0 <= dropout < 1.0:
            raise ValueError("dropout must be in [0, 1)")
        if task not in {"regression", "classification"}:
            raise ValueError("task must be regression or classification")
        self.hidden = hidden
        self.dropout = dropout
        self.l2 = l2
        self.lr = lr
        self.max_iter = max_iter
        self.task = task
        self.random_state = random_state
        self.loss_curve_: list[float] = []
        self._W1: np.ndarray | None = None
        self._b1: np.ndarray | None = None
        self._W2: np.ndarray | None = None
        self._b2: np.ndarray | None = None

    def _init_weights(self, n_in: int, rng: np.random.Generator) -> None:
        scale1 = np.sqrt(2.0 / n_in)
        scale2 = np.sqrt(2.0 / self.hidden)
        self._W1 = rng.normal(scale=scale1, size=(n_in, self.hidden))
        self._b1 = np.zeros(self.hidden)
        self._W2 = rng.normal(scale=scale2, size=(self.hidden, 1))
        self._b2 = np.zeros(1)

    def _forward(
        self, X: np.ndarray, rng: np.random.Generator | None = None
    ) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
        assert self._W1 is not None and self._W2 is not None
        hidden = np.maximum(0.0, X @ self._W1 + self._b1)
        mask = np.ones_like(hidden)
        if rng is not None and self.dropout > 0:
            mask = (rng.random(hidden.shape) >= self.dropout).astype(float)
            hidden = hidden * mask / (1.0 - self.dropout)
        raw = hidden @ self._W2 + self._b2
        out = 1.0 / (1.0 + np.exp(-np.clip(raw, -500.0, 500.0))) if self.task == "classification" else raw
        return hidden, mask, out

    def fit(self, X: np.ndarray, y: np.ndarray) -> MLP:
        X, y = check_xy(X, y)
        y = y.reshape(-1, 1)
        rng = np.random.default_rng(self.random_state)
        self._init_weights(X.shape[1], rng)
        n = X.shape[0]
        self.loss_curve_.clear()
        for _ in range(self.max_iter):
            hidden, mask, out = self._forward(X, rng)
            if self.task == "classification":
                p = np.clip(out, 1e-12, 1.0 - 1e-12)
                loss = float(-np.mean(y * np.log(p) + (1.0 - y) * np.log(1.0 - p)))
                d_out = (p - y) / n
            else:
                loss = float(np.mean((out - y) ** 2))
                d_out = 2.0 * (out - y) / n
            loss += 0.5 * self.l2 * (float(np.sum(self._W1**2)) + float(np.sum(self._W2**2)))
            self.loss_curve_.append(loss)

            d_W2 = hidden.T @ d_out + self.l2 * self._W2
            d_b2 = d_out.sum(axis=0)
            d_hidden = (d_out @ self._W2.T) * mask / (1.0 - self.dropout if self.dropout > 0 else 1.0)
            d_hidden *= (hidden > 0).astype(float)
            d_W1 = X.T @ d_hidden + self.l2 * self._W1
            d_b1 = d_hidden.sum(axis=0)

            self._W1 = self._W1 - self.lr * d_W1
            self._b1 = self._b1 - self.lr * d_b1
            self._W2 = self._W2 - self.lr * d_W2
            self._b2 = self._b2 - self.lr * d_b2
        return self

    def predict(self, X: np.ndarray) -> np.ndarray:
        if self._W1 is None:
            raise RuntimeError("Call fit() first")
        X, _ = check_xy(X)
        _, _, out = self._forward(X, rng=None)
        out = out.ravel()
        if self.task == "classification":
            return (out >= 0.5).astype(int)
        return out

    def predict_proba(self, X: np.ndarray) -> np.ndarray:
        if self.task != "classification":
            raise RuntimeError("predict_proba is for classification")
        if self._W1 is None:
            raise RuntimeError("Call fit() first")
        X, _ = check_xy(X)
        _, _, out = self._forward(X, rng=None)
        return out.ravel()
