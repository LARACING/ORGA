# Branching and workflow

## Table of Contents

- [Branching and workflow](#branching-and-workflow)
  - [Table of Contents](#table-of-contents)
  - [Branch Model](#branch-model)
    - [`main`](#main)
    - [`feature/nameOfFeature`](#featurenameoffeature)
    - [`feature/nameOfFeature/nameOfSubIssue`](#featurenameoffeaturenameofsubissue)
    - [`fix/nameOfFix`](#fixnameoffix)
  - [GitHub Issue Structure](#github-issue-structure)
    - [Feature](#feature)
      - [1. Create a Feature Issue](#1-create-a-feature-issue)
      - [2. Create Sub-Issues](#2-create-sub-issues)
      - [3. Create Pull Request](#3-create-pull-request)
        - [When to expect review](#when-to-expect-review)
    - [Pull Requests](#pull-requests)
      - [Review](#review)
        - [Functional Correctness](#functional-correctness)
        - [Test Coverage](#test-coverage)
        - [Code Quality](#code-quality)
        - [Architecture \& Design](#architecture--design)
        - [Git Hygiene](#git-hygiene)
        - [Approval means](#approval-means)
        - [If issues arrise](#if-issues-arrise)
      - [Merge](#merge)
        - [Merge Rules](#merge-rules)
        - [Merge Method](#merge-method)
        - [Post Merge](#post-merge)

## Branch Model

### `main`

- Production Branch
- Always deployable
- Protected on GitHub
- No direct commits
- No merges outside Pull Requests(PR's)

### `feature/nameOfFeature`

- Feature Branch
- Should be deployable
- Non-Protected
- No direct commits if sub-issue branches exist
- Typically no merges outside PR's

### `feature/nameOfFeature/nameOfSubIssue`

- Issue Branch
- Active developement of the issue
- Non-Protected
- Direct commits
- Typically no merges outside PR's

### `fix/nameOfFix`

- Bugfix Branch
- Active fixing of Bug
- Non-Protected
- Direct commits
- Typically no merges outside PR's

## GitHub Issue Structure

Mandatory for every developement effort.

### Feature

#### 1. Create a Feature Issue

- Tagged with Type `Feature`
- Labelled according to its functionality
- Represents a complete Feature
- Assigned to maintainer
- According branch is created (see[Rules](#featurenameoffeature))

> Example: Implementation of CAN Interface

#### 2. Create Sub-Issues

- Labelled according to its functionality
- Represents one developement part of a Feature
- Assigned to maintainer
- According branch is created (see[Rules](#featurenameoffeaturenameofsubissue)))

> Example: Implementation of Error Handling in CAN Interface

#### 3. Create Pull Request

- Created from dev branch to merge branch
- Assigned to maintainer
- Reviewer assigned accordingly
- Converted to draft until review is expected

##### When to expect review

- Feature / issue is fully implemented
- @Feature: Minimum 90% unit test coverage except valid explanation
- @Feature: All tests pass
- @Feature: CI passes

### Pull Requests

#### Review

The reviewer evaluates the Pull Request according to:

##### Functional Correctness

- Feature fulfills the main issue description
- All sub-issues are resolved

##### Test Coverage

- Minimum 90% unit test coverage except with valid explanation
- New logic is covered by tests
- Edge cases are tested
- Tests are deterministic and stable
- All CI checks are green

##### Code Quality

- Clear and consistent naming
- Small, focused commits
- No uneccassary complexity
- No duplicated logic
- No dead code

##### Architecture & Design

- Conforms to project structure
- No violations of layering or modular boundaries
- No hidden coupling introduced
- Interfaces remain clean and stable

##### Git Hygiene

- Correct branch naming (feature/nameOfFeature/nameOfIssue)
- Signed commits
- Clean commit history
- No unrelated changes

> Non-feature PRs are handled more flexibly at the discretion of the reviewer and assignee.

##### Approval means

- Reviewer explicitly approves in GitHub
- No unresolved review comments.

##### If issues arrise

1. Reviewer adds review comments
2. Reviewer requests changes
3. Assignee addresses the feedback and fixes the issues
4. Assignee re-requests review

#### Merge

The assigned maintainer merges the Pull Request only after:

- Reviewer approval
- All CI checks pass
- 90%+ coverage is verified

##### Merge Rules

- Only the assigned maintainer may merge
- No self-merging
- No merging without review

##### Merge Method

Merge without squash

##### Post Merge

The assignee must:

- Verify CI completion on the target branch
- Address hotfixes immediately
- Delete the development branch
- Close the issue and Pull Request if not done automatically
