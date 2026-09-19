"""Feature helpers you actually reach for in notebooks."""

from __future__ import annotations

import numpy as np


def add_intercept(X: np.ndarray) -> np.ndarray:
    X = np.asarray(X, dtype=float)
    if X.ndim == 1:
        X = X.reshape(-1, 1)
    return np.column_stack([np.ones(X.shape[0]), X])


def standardize(
    X: np.ndarray,
    mean: np.ndarray | None = None,
    std: np.ndarray | None = None,
    eps: float = 1e-12,
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    X = np.asarray(X, dtype=float)
    if mean is None:
        mean = X.mean(axis=0)
    if std is None:
        std = X.std(axis=0)
    std = np.where(std < eps, 1.0, std)
    return (X - mean) / std, mean, std


def polynomial_features(X: np.ndarray, degree: int = 2) -> np.ndarray:
    """Powers 1..degree per column. No interaction terms — keep it readable."""
    if degree < 1:
        raise ValueError("degree must be >= 1")
    X = np.asarray(X, dtype=float)
    if X.ndim == 1:
        X = X.reshape(-1, 1)
    cols = [X ** d for d in range(1, degree + 1)]
    return np.concatenate(cols, axis=1)
