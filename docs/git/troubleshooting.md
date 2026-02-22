# Troubleshooting

> If you are unsure just contact someone via e.g. Telegram before changing anything.

## Table of Contents

- [Troubleshooting](#troubleshooting)
  - [Table of Contents](#table-of-contents)
  - [Undoing Local Changes](#undoing-local-changes)
    - [Discard Unstaged Changes](#discard-unstaged-changes)
    - [Unstage Files](#unstage-files)
    - [Amend Last Commit (Before Push)](#amend-last-commit-before-push)
  - [Fixing a Wrong Commit (Not Yet Pushed)](#fixing-a-wrong-commit-not-yet-pushed)
    - [Soft Reset (Keep Changes)](#soft-reset-keep-changes)
    - [Mixed Reset (Keep Changes Unstaged)](#mixed-reset-keep-changes-unstaged)
    - [Hard Reset (Dangerous)](#hard-reset-dangerous)
  - [Fixing a Pushed Commit (Feature Branch)](#fixing-a-pushed-commit-feature-branch)
  - [Never Rewrite `main`](#never-rewrite-main)
  - [Revert a Commit (Safe for Shared Branches)](#revert-a-commit-safe-for-shared-branches)
  - [Handling Conflicts](#handling-conflicts)
  - [Detached HEAD](#detached-head)
  - [Lost Commits Recovery](#lost-commits-recovery)
  - [Accidentally Committed to Wrong Branch](#accidentally-committed-to-wrong-branch)
  - [CI Fails After Merge](#ci-fails-after-merge)
  - [When to Contact Admin](#when-to-contact-admin)

## Undoing Local Changes

### Discard Unstaged Changes

``` bash
git restore <file>
```

Discard all local unstaged changes:

``` bash
git restore .
```

### Unstage Files

``` bash
git restore --staged <file>
```

### Amend Last Commit (Before Push)

``` bash
git commit --amend
```

Use only if: - Commit is not pushed - You are on your own branch

## Fixing a Wrong Commit (Not Yet Pushed)

### Soft Reset (Keep Changes)

``` bash
git reset --soft HEAD~1
```

Moves HEAD back one commit but keeps changes staged.

### Mixed Reset (Keep Changes Unstaged)

``` bash
git reset HEAD~1
```

### Hard Reset (Dangerous)

``` bash
git reset --hard HEAD~1
```

Removes commit and changes permanently.

Use only if: - Changes are not needed - Commit was not pushed

## Fixing a Pushed Commit (Feature Branch)

If the branch is not shared, you may:

``` bash
git rebase -i HEAD~n
```

Then:

``` bash
git push --force-with-lease
```

Allowed only if:

- It is your own branch
- No one else is working on it
- No admin restriction applies

If unsure, contact admin.

## Never Rewrite `main`

- Do not rebase `main`
- Do not reset `main`
- Do not force push to `main`
- Fix issues via a new PR

## Revert a Commit (Safe for Shared Branches)

If something is already merged to `main`:

``` bash
git revert <commit-hash>
```

Creates a new commit that undoes the change.

Push normally and open a PR if required.

## Handling Conflicts

When rebasing or merging:

    <<<<<<< HEAD
    current changes
    =======
    incoming changes
    >>>>>>> branch

Resolution flow:

1. Edit file
2. Remove conflict markers
3. Stage file:

``` bash
git add <file>
```

1. Continue:

``` bash
git rebase --continue
```

Abort if needed:

``` bash
git rebase --abort
```

## Detached HEAD

If you see:

    You are in 'detached HEAD' state

Fix by switching to a branch:

``` bash
git checkout main
```

Or create a branch from current state:

``` bash
git checkout -b feature/new-branch
```

## Lost Commits Recovery

Use reflog:

``` bash
git reflog
```

Find commit hash, then:

``` bash
git checkout <hash>
```

Or restore:

``` bash
git reset --hard <hash>
```

## Accidentally Committed to Wrong Branch

If not pushed:

``` bash
git reset --soft HEAD~1
git checkout correct-branch
git commit
```

If pushed to a feature branch: - Fix on that branch\

- Or revert

If pushed to `main`: - Immediately inform admin\

- Create revert PR

## CI Fails After Merge

1. Identify failing job
2. Fix issue in a new branch
3. Open hotfix PR
4. Follow full review process

Never push directly to `main` to apply a quick fix.

## When to Contact Admin

- Accidental push to `main`
- Force push required
- Branch protection violation
- Corrupted history
- Unrecoverable merge situation
