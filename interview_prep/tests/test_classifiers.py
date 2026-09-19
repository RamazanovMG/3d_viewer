from __future__ import annotations

import numpy as np

from interview_prep.metrics import accuracy
from interview_prep.models import KNN, LogisticRegression, MLP
from interview_prep.regularizers import L2


def _blobs(seed: int = 0):
    rng = np.random.default_rng(seed)
    x0 = rng.normal(loc=-1.5, scale=0.4, size=(80, 2))
    x1 = rng.normal(loc=1.5, scale=0.4, size=(80, 2))
    X = np.vstack([x0, x1])
    y = np.array([0] * 80 + [1] * 80)
    return X, y


def test_logistic_separates_blobs():
    X, y = _blobs()
    clf = LogisticRegression(lr=0.3, max_iter=1500).fit(X, y)
    assert accuracy(y, clf.predict(X)) > 0.95


def test_logistic_l2_shrinks_weights():
    X, y = _blobs(1)
    plain = LogisticRegression(lr=0.3, max_iter=1500).fit(X, y)
    ridge = LogisticRegression(regularizer=L2(2.0), lr=0.3, max_iter=1500).fit(X, y)
    assert np.linalg.norm(ridge.coef_) < np.linalg.norm(plain.coef_)


def test_knn_classification():
    X, y = _blobs(2)
    pred = KNN(k=5).fit(X, y).predict(X)
    assert accuracy(y, pred) > 0.9


def test_mlp_fits_sine():
    rng = np.random.default_rng(0)
    X = rng.uniform(-np.pi, np.pi, size=(300, 1))
    y = np.sin(X.ravel())
    net = MLP(hidden=32, lr=0.05, max_iter=2500, task="regression", random_state=0).fit(X, y)
    assert np.mean((net.predict(X) - y) ** 2) < 0.05
