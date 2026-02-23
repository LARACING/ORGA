# Initial Setup

For the configuration please use the Git Bash if you have not setup your PATH yet.

## Git Setup

### Set identity

```bash
git config --global user.name "Your Name"
git config --global user.email "your@email.com"
```

> For Usage with GitHub it is essential to have the same email as your GitHub profile.

### Set default branch to main

Since Git 3.0 `main` is the default branch instead of the previous `master`.

```bash
git config --global init.defaultBranch main
```

### Recommended

```bash
git config --global pull.rebase false
git config --global core.editor "code --wait"
```

## SSH Authentication (GitHub)

Do **not** use HTTPS + passwords. Use SSH.

### Generate SSH Key

```bash
ssh-keygen -t ed25519 -C "you@domain.com"
```

### Activate for your OS

Accept default path:

```bash
~/.ssh/id_ed25519
```

Start agent:

```bash

eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
```

### Add SSH Key to GitHub

#### Copy public key

```bash
cat ~/.ssh/id_ed25519.pub
```

On GitHub:

1. Go to Settings
2. SSH and GPG Keys
3. New SSH key
4. Paste Key

#### Test Connection

```bash
ssh -T git@github.com
```

Expected:

```bash
Hi <username>! You've successfully authenticated...
```

## SSH Signing (GitHub)

On our Repos commit signing, so you have to enable it.
This ensures commits are cryptographically verifiied on GitHub.

### Enable SSH Signing in Git

```bash
git config --global gpg.format ssh
git config --global user.signingkey ~/.ssh/id_ed25519.pub
git config --global commit.gpgsign true
```

### Add Signing Key to GitHub

In GitHub:

1. Settings
2. SSH and GPG Keys
3. New SSH Key
4. Select Signing Key
5. Paste the same public Key

### Test Signed Commit

In a tmp directory initialize a git repo.

```bash
git init
```

Then create a test commit.

```bash
git commit --allow-empty -m "Test commit"
```

Check:

```bash
git log --show-signature
```

Expected output should be:

```bash
Good "git" signature for <username>...
```
