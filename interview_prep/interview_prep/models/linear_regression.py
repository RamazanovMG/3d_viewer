from __future__ import annotations

import numpy as np

from interview_prep.models.base import (
    BaseModel,
    check_xy,
    regularizer_grad,
    regularizer_penalty,
)
from interview_prep.preprocessing import add_intercept
from interview_prep.regularizers import L2, NoRegularization, Regularizer, as_regularizer


class LinearRegression(BaseModel):
    """OLS / Ridge / Lasso / ElasticNet.

    solver='auto' uses the normal equation for unregularized and L2, GD otherwise.
    Intercept is never regularized.
    """

    def __init__(
        self,
        regularizer: Regularizer | None = None,
        lr: float = 0.1,
        max_iter: int = 3000,
        tol: float = 1e-8,
        solver: str = "auto",
        fit_intercept: bool = True,
        random_state: int | None = None,
    ) -> None:
        self.regularizer = as_regularizer(regularizer)
        self.lr = lr
        self.max_iter = max_iter
        self.tol = tol
        self.solver = solver
        self.fit_intercept = fit_intercept
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

    def _loss(self, Xb: np.ndarray, y: np.ndarray, weights: np.ndarray) -> float:
        residual = Xb @ weights - y
        return 0.5 * float(np.mean(residual**2)) + regularizer_penalty(
            self.regularizer, weights, self.fit_intercept
        )

    def _fit_normal(self, Xb: np.ndarray, y: np.ndarray) -> np.ndarray:
        n, n_features = Xb.shape
        xtx = Xb.T @ Xb
        if isinstance(self.regularizer, L2) and self.regularizer.lam > 0:
            # mean-MSE GD uses X'X/n + lam I, so the sum form is X'X + n lam I
            penalty = (n * self.regularizer.lam) * np.eye(n_features)
            if self.fit_intercept:
                penalty[0, 0] = 0.0
            xtx = xtx + penalty
        return np.linalg.solve(xtx, Xb.T @ y)

    def _fit_gd(self, Xb: np.ndarray, y: np.ndarray) -> np.ndarray:
        rng = np.random.default_rng(self.random_state)
        weights = rng.normal(scale=0.01, size=Xb.shape[1])
        n = Xb.shape[0]
        self.loss_curve_.clear()
        for _ in range(self.max_iter):
            residual = Xb @ weights - y
            grad = (Xb.T @ residual) / n + regularizer_grad(
                self.regularizer, weights, self.fit_intercept
            )
            weights = weights - self.lr * grad
            self.loss_curve_.append(self._loss(Xb, y, weights))
            if np.linalg.norm(grad) < self.tol:
                break
        return weights

    def _choose_solver(self) -> str:
        if self.solver != "auto":
            return self.solver
        if isinstance(self.regularizer, (L2, NoRegularization)):
            return "normal"
        return "gd"

    def fit(self, X: np.ndarray, y: np.ndarray) -> LinearRegression:
        X, y = check_xy(X, y)
        Xb = self._design(X)
        solver = self._choose_solver()
        if solver == "normal":
            weights = self._fit_normal(Xb, y)
            self.loss_curve_ = [self._loss(Xb, y, weights)]
        elif solver == "gd":
            weights = self._fit_gd(Xb, y)
        else:
            raise ValueError("solver must be 'auto', 'normal', or 'gd'")
        self._unpack(weights)
        return self

    def predict(self, X: np.ndarray) -> np.ndarray:
        if self.coef_ is None:
            raise RuntimeError("Call fit() first")
        X, _ = check_xy(X)
        return self._design(X) @ (
            np.concatenate([[self.intercept_], self.coef_]) if self.fit_intercept else self.coef_
        )
