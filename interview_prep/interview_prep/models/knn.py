from __future__ import annotations

import numpy as np

from interview_prep.models.base import BaseModel, check_xy


class KNN(BaseModel):
    """Brute-force k-NN. task='classification' or 'regression'."""

    def __init__(self, k: int = 5, task: str = "classification") -> None:
        if k < 1:
            raise ValueError("k must be >= 1")
        if task not in {"classification", "regression"}:
            raise ValueError("task must be classification or regression")
        self.k = k
        self.task = task
        self._X: np.ndarray | None = None
        self._y: np.ndarray | None = None

    def fit(self, X: np.ndarray, y: np.ndarray) -> KNN:
        self._X, self._y = check_xy(X, y)
        return self

    def predict(self, X: np.ndarray) -> np.ndarray:
        if self._X is None or self._y is None:
            raise RuntimeError("Call fit() first")
        X, _ = check_xy(X)
        dist = np.sqrt(((X[:, None, :] - self._X[None, :, :]) ** 2).sum(axis=2))
        nn = np.argpartition(dist, kth=min(self.k, dist.shape[1] - 1), axis=1)[:, : self.k]
        votes = self._y[nn]
        if self.task == "regression":
            return votes.mean(axis=1)
        preds = np.empty(len(X), dtype=self._y.dtype)
        for i, row in enumerate(votes):
            values, counts = np.unique(row, return_counts=True)
            preds[i] = values[np.argmax(counts)]
        return preds
