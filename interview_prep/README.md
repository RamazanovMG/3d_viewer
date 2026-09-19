# interview_prep

Python namespace + notebooks for grinding ML interviews and poking at models / regularizers.

Implementations are numpy-from-scratch on purpose — you can see the loss, the gradient, and what L1/L2/dropout actually do. sklearn is only there for datasets and as a sanity check.

```python
from interview_prep.models import LinearRegression, LogisticRegression, MLP, KNN
from interview_prep.regularizers import L1, L2, ElasticNet
```

## Layout

```
interview_prep/          # importable package (the namespace)
  models/                # linear, logistic, mlp, knn
  regularizers.py        # L1, L2, ElasticNet
  metrics.py
  preprocessing.py
notebooks/               # throw experiments in here
tests/
```

## Setup

```bash
cd interview_prep
python3 -m venv .venv
source .venv/bin/activate
pip install -e ".[dev]"
make test
make notebook
```

If you already have a venv: `pip install -e ".[dev]"` from this directory, then `jupyter lab notebooks`.

## Quick poke

```python
import numpy as np
from interview_prep.models import LinearRegression
from interview_prep.regularizers import L1, L2

rng = np.random.default_rng(0)
X = rng.normal(size=(200, 10))
w = np.array([3, -2, 0, 0, 1.5, 0, 0, 0, 0, 0], dtype=float)
y = X @ w + rng.normal(scale=0.3, size=200)

ols = LinearRegression().fit(X, y)
ridge = LinearRegression(regularizer=L2(lam=0.5)).fit(X, y)
lasso = LinearRegression(regularizer=L1(lam=0.05), solver="gd").fit(X, y)

ols.coef_, ridge.coef_, lasso.coef_
```

Start with `notebooks/01_linear_models_regularization.ipynb`. Copy `notebooks/00_scratch.ipynb` when you want a dirty playground.

## Adding stuff

Keep new models under `interview_prep/models/` and export them from `models/__init__.py`. Regularizers stay composable objects so you can swap them on the same estimator instead of growing a zoo of `RidgeClassifier` clones.
