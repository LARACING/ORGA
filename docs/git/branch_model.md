# Branch Model

## `main`

- Production Branch
- Always deployable
- Protected on GitHub
- No direct commits
- No merges outside Pull Requests(PR's)

## `feature/nameOfFeature`

- Feature Branch
- Should be deployable
- Non-Protected
- No direct commits if sub-issue branches exist
- Typically no merges outside PR's

## `feature/nameOfFeature/nameOfSubIssue`

- Issue Branch
- Active developement of the issue
- Non-Protected
- Direct commits
- Typically no merges outside PR's

## `fix/nameOfFix`

- Bugfix Branch
- Active fixing of Bug
- Non-Protected
- Direct commits
- Typically no merges outside PR's
