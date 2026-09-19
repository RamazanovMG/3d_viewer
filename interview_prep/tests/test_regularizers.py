from __future__ import annotations

import numpy as np
import pytest

from interview_prep.regularizers import ElasticNet, L1, L2, NoRegularization


def test_l2_penalty_and_grad():
    reg = L2(2.0)
    w = np.array([3.0, -4.0])
    assert reg.penalty(w) == pytest.approx(0.5 * 2.0 * 25.0)
    np.testing.assert_allclose(reg.grad(w), 2.0 * w)


def test_l1_penalty_and_grad():
    reg = L1(3.0)
    w = np.array([2.0, 0.0, -1.0])
    assert reg.penalty(w) == pytest.approx(9.0)
    np.testing.assert_allclose(reg.grad(w), np.array([3.0, 0.0, -3.0]))


def test_elastic_net_splits_l1_l2():
    w = np.array([1.0, -2.0])
    mixed = ElasticNet(lam=2.0, l1_ratio=0.25)
    expected = L1(0.5).penalty(w) + L2(1.5).penalty(w)
    assert mixed.penalty(w) == pytest.approx(expected)


def test_none_is_zero():
    w = np.ones(4)
    assert NoRegularization().penalty(w) == 0.0
    np.testing.assert_allclose(NoRegularization().grad(w), np.zeros(4))
