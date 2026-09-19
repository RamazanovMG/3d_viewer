from __future__ import annotations

import numpy as np

from interview_prep.metrics import mse
from interview_prep.models import LinearRegression
from interview_prep.regularizers import L1, L2


def test_recovers_line():
    rng = np.random.default_rng(0)
    X = rng.normal(size=(200, 1))
    y = 4.0 * X.ravel() + 1.5
    model = LinearRegression().fit(X, y)
    assert abs(model.intercept_ - 1.5) < 1e-6
    assert abs(model.coef_[0] - 4.0) < 1e-6
    assert mse(y, model.predict(X)) < 1e-12


def test_ridge_shrinks_coefs():
    rng = np.random.default_rng(1)
    X = rng.normal(size=(80, 12))
    y = X @ np.linspace(2, -1, 12) + rng.normal(scale=0.4, size=80)
    ols = LinearRegression().fit(X, y)
    ridge = LinearRegression(regularizer=L2(lam=5.0)).fit(X, y)
    assert np.linalg.norm(ridge.coef_) < np.linalg.norm(ols.coef_)


def test_lasso_drives_noise_coords_toward_zero():
    rng = np.random.default_rng(2)
    n, p = 150, 8
    X = rng.normal(size=(n, p))
    true = np.zeros(p)
    true[:2] = [3.0, -2.0]
    y = X @ true + rng.normal(scale=0.1, size=n)
    lasso = LinearRegression(regularizer=L1(lam=0.05), solver="gd", lr=0.05, max_iter=4000).fit(X, y)
    assert np.max(np.abs(lasso.coef_[2:])) < np.min(np.abs(lasso.coef_[:2]))


def test_gd_matches_normal_for_ridge():
    rng = np.random.default_rng(3)
    X = rng.normal(size=(60, 4))
    y = X @ np.array([1.0, -0.5, 0.2, 0.0]) + 0.3
    kw = dict(regularizer=L2(0.2), fit_intercept=True)
    closed = LinearRegression(solver="normal", **kw).fit(X, y)
    gd = LinearRegression(solver="gd", lr=0.1, max_iter=8000, **kw).fit(X, y)
    np.testing.assert_allclose(gd.coef_, closed.coef_, atol=1e-3)
    assert abs(gd.intercept_ - closed.intercept_) < 1e-3
