from __future__ import annotations

import numpy as np

from interview_prep.models.base import (
    BaseModel,
    check_xy,
    regularizer_grad,
    regularizer_penalty,
)
from interview_prep.preprocessing import add_intercept
from interview_prep.regularizers import Regularizer, as_regularizer


def sigmoid(z: np.ndarray) -> np.ndarray:
    z = np.clip(z, -500.0, 500.0)
    return 1.0 / (1.0 + np.exp(-z))


class LogisticRegression(BaseModel):
    """Binary logistic regression with optional L1/L2/ElasticNet."""

    def __init__(
        self,
        regularizer: Regularizer | None = None,
        lr: float = 0.2,
        max_iter: int = 3000,
        tol: float = 1e-8,
        fit_intercept: bool = True,
        threshold: float = 0.5,
        random_state: int | None = None,
    ) -> None:
        self.regularizer = as_regularizer(regularizer)
        self.lr = lr
        self.max_iter = max_iter
        self.tol = tol
        self.fit_intercept = fit_intercept
        self.threshold = threshold
        self.random_state = random_state
        self.coef_: np.ndarray | None = None
        self.intercept_: float = 0.0
        self.loss_curve_: list[float] = []

    def _design(self, X: np.ndarray) -> np.ndarray:
        return add_intercept(X) if self.fit_intercept else np.asarray(X, dtype=float)

    def _unpack(self, weights: np.ndarray) -> None:
        if self.fit_intercept:
            self.intercept_ = float(weights[0])
            self.coef_ = weights[1:].copy()
        else:
            self.intercept_ = 0.0
            self.coef_ = weights.copy()

    def fit(self, X: np.ndarray, y: np.ndarray) -> LogisticRegression:
        X, y = check_xy(X, y)
        if not np.isin(y, [0.0, 1.0]).all():
            raise ValueError("y must be binary {0, 1}")
        Xb = self._design(X)
        rng = np.random.default_rng(self.random_state)
        weights = rng.normal(scale=0.01, size=Xb.shape[1])
        n = Xb.shape[0]
        self.loss_curve_.clear()
        for _ in range(self.max_iter):
            p = sigmoid(Xb @ weights)
            grad = (Xb.T @ (p - y)) / n + regularizer_grad(
                self.regularizer, weights, self.fit_intercept
            )
            weights = weights - self.lr * grad
            p = np.clip(p, 1e-12, 1.0 - 1e-12)
            loss = float(-np.mean(y * np.log(p) + (1.0 - y) * np.log(1.0 - p)))
            loss += regularizer_penalty(self.regularizer, weights, self.fit_intercept)
            self.loss_curve_.append(loss)
            if np.linalg.norm(grad) < self.tol:
                break
        self._unpack(weights)
        return self

    def predict_proba(self, X: np.ndarray) -> np.ndarray:
        if self.coef_ is None:
            raise RuntimeError("Call fit() first")
        X, _ = check_xy(X)
        weights = (
            np.concatenate([[self.intercept_], self.coef_]) if self.fit_intercept else self.coef_
        )
        return sigmoid(self._design(X) @ weights)

    def predict(self, X: np.ndarray) -> np.ndarray:
        return (self.predict_proba(X) >= self.threshold).astype(int)
