from __future__ import annotations

from abc import ABC, abstractmethod

import numpy as np

from interview_prep.regularizers import Regularizer, as_regularizer


class BaseModel(ABC):
    @abstractmethod
    def fit(self, X: np.ndarray, y: np.ndarray) -> BaseModel: ...

    @abstractmethod
    def predict(self, X: np.ndarray) -> np.ndarray: ...


def check_xy(X: np.ndarray, y: np.ndarray | None = None) -> tuple[np.ndarray, np.ndarray | None]:
    X = np.asarray(X, dtype=float)
    if X.ndim == 1:
        X = X.reshape(-1, 1)
    if y is None:
        return X, None
    y = np.asarray(y, dtype=float).ravel()
    if X.shape[0] != y.shape[0]:
        raise ValueError(f"X/y length mismatch: {X.shape[0]} vs {y.shape[0]}")
    return X, y


def regularizer_grad(regularizer: Regularizer | None, weights: np.ndarray, fit_intercept: bool) -> np.ndarray:
    reg = as_regularizer(regularizer)
    grad = np.zeros_like(weights, dtype=float)
    if fit_intercept:
        grad[1:] = reg.grad(weights[1:])
    else:
        grad = reg.grad(weights)
    return grad


def regularizer_penalty(regularizer: Regularizer | None, weights: np.ndarray, fit_intercept: bool) -> float:
    reg = as_regularizer(regularizer)
    core = weights[1:] if fit_intercept else weights
    return reg.penalty(core)
