"""Composable weight penalties. Applied to non-intercept weights only."""

from __future__ import annotations

from abc import ABC, abstractmethod

import numpy as np


class Regularizer(ABC):
    @abstractmethod
    def penalty(self, weights: np.ndarray) -> float:
        """Scalar penalty added to the mean loss."""

    @abstractmethod
    def grad(self, weights: np.ndarray) -> np.ndarray:
        """Gradient of penalty() w.r.t. weights."""


class NoRegularization(Regularizer):
    def penalty(self, weights: np.ndarray) -> float:
        return 0.0

    def grad(self, weights: np.ndarray) -> np.ndarray:
        return np.zeros_like(weights, dtype=float)


class L2(Regularizer):
    """Ridge: 0.5 * lam * ||w||^2."""

    def __init__(self, lam: float = 1.0) -> None:
        if lam < 0:
            raise ValueError("lam must be >= 0")
        self.lam = float(lam)

    def penalty(self, weights: np.ndarray) -> float:
        return 0.5 * self.lam * float(np.sum(weights * weights))

    def grad(self, weights: np.ndarray) -> np.ndarray:
        return self.lam * weights


class L1(Regularizer):
    """Lasso: lam * ||w||_1. Subgradient uses sign(0)=0."""

    def __init__(self, lam: float = 1.0) -> None:
        if lam < 0:
            raise ValueError("lam must be >= 0")
        self.lam = float(lam)

    def penalty(self, weights: np.ndarray) -> float:
        return self.lam * float(np.sum(np.abs(weights)))

    def grad(self, weights: np.ndarray) -> np.ndarray:
        return self.lam * np.sign(weights)


class ElasticNet(Regularizer):
    """lam * (l1_ratio * ||w||_1 + (1-l1_ratio) * 0.5 * ||w||^2)."""

    def __init__(self, lam: float = 1.0, l1_ratio: float = 0.5) -> None:
        if not 0.0 <= l1_ratio <= 1.0:
            raise ValueError("l1_ratio must be in [0, 1]")
        self.l1 = L1(lam * l1_ratio)
        self.l2 = L2(lam * (1.0 - l1_ratio))
        self.lam = float(lam)
        self.l1_ratio = float(l1_ratio)

    def penalty(self, weights: np.ndarray) -> float:
        return self.l1.penalty(weights) + self.l2.penalty(weights)

    def grad(self, weights: np.ndarray) -> np.ndarray:
        return self.l1.grad(weights) + self.l2.grad(weights)


def as_regularizer(regularizer: Regularizer | None) -> Regularizer:
    return NoRegularization() if regularizer is None else regularizer
