# Cheatsheet

Quick reference for daily workflow.

## Table of Contents

- [Cheatsheet](#cheatsheet)
  - [Table of Contents](#table-of-contents)
  - [Clone (SSH)](#clone-ssh)
  - [Start Working on a Sub-Issue](#start-working-on-a-sub-issue)
  - [Check Status](#check-status)
  - [Stage Changes](#stage-changes)
  - [Commit (Signed Automatically)](#commit-signed-automatically)
  - [Update Branch Before Push](#update-branch-before-push)
  - [Push Branch](#push-branch)
  - [Fix Last Commit (Before Push)](#fix-last-commit-before-push)
  - [Interactive Rebase (Local Cleanup)](#interactive-rebase-local-cleanup)
  - [Revert a Commit (Safe on Shared Branches)](#revert-a-commit-safe-on-shared-branches)
  - [Resolve Conflict](#resolve-conflict)
  - [Delete Branch After Merge](#delete-branch-after-merge)
  - [View History](#view-history)
  - [Check Remotes](#check-remotes)
  - [Coverage Reminder](#coverage-reminder)

## Clone (SSH)

``` bash
git clone git@github.com:org/repo.git
cd repo
```

## Start Working on a Sub-Issue

``` bash
git checkout main
git pull --rebase
git checkout -b feature/nameOfFeature/nameOfIssue
```

## Check Status

``` bash
git status
```

## Stage Changes

``` bash
git add <file>
git add .
```

## Commit (Signed Automatically)

``` bash
git commit -m "Add CAN timeout validation"
```

## Update Branch Before Push

``` bash
git pull --rebase origin main
```

## Push Branch

``` bash
git push -u origin feature/nameOfFeature/nameOfIssue
```

## Fix Last Commit (Before Push)

``` bash
git commit --amend
```

## Interactive Rebase (Local Cleanup)

``` bash
git rebase -i HEAD~n
```

After rebase:

``` bash
git push --force-with-lease
```

(Only allowed on own branch and after approval if required.)

## Revert a Commit (Safe on Shared Branches)

``` bash
git revert <commit-hash>
```

## Resolve Conflict

``` bash
# edit file
git add <file>
git rebase --continue
```

Abort:

``` bash
git rebase --abort
```

## Delete Branch After Merge

Local:

``` bash
git branch -d feature/nameOfFeature/nameOfIssue
```

Remote:

``` bash
git push origin --delete feature/nameOfFeature/nameOfIssue
```

## View History

``` bash
git log --oneline --graph --decorate
```

## Check Remotes

``` bash
git remote -v
```

## Coverage Reminder

Before opening PR:

- ≥ 90% unit test coverage
- CI green
- All sub-issues resolved
- Feature complete
