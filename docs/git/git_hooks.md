# Git Hooks

To enforce consistency for code formats etc. git hooks are a good tool...

## What you need to do?

- Install pre-commit via ```brew install pre-commit```, ```apt install pre-commit```
- (Windows users may use [pre-commit.com](https://pre-commit.com) and follow installation guide there)
- Run ```pre-commit install``` in the Repo's root
- Run ```pre-commit run --all``` to enforce a full reload of all hook actions
- Every time you want to commit, the hooks are executed in the background and may update invalid code formats etc.
- If a commit fails due to hook interfearence make sure to run ```git add .
``` to stage the changed made by the hook
- Then you can try to commit again
