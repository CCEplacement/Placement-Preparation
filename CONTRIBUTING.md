# 🤝 Contributing Guidelines

Welcome! We are excited that you are part of this collaborative placement preparation workspace. To maintain structure and ensure a smooth review process for all **45 students**, please follow these contributing guidelines.

---

## 🚫 Critical Policy: Folder Ownership
* **You are only allowed to create, modify, or delete files inside your own student directory:** `STUDENTS/<your-github-username>/`.
* Do **NOT** modify the global `TASKS/`, `RESOURCES/`, `SEMINARS/`, or another student's directory. 
* Pull Requests modifying restricted directories will be automatically requested for revision or closed by the administrators.

---

## 🔄 Weekly Submission Workflow

Follow these exact steps every week to submit your notes, solved problems, and updates:

### 1. Fork & Clone (One-Time Setup)
1. Fork the repository to your own GitHub account: [https://github.com/sarathi-sai7/Placement-Preparation](https://github.com/sarathi-sai7/Placement-Preparation)
2. Clone your fork locally:
   ```bash
   git clone https://github.com/<your-github-username>/Placement-Preparation.git
   cd Placement-Preparation
   ```
3. Set the upstream remote to stay synced with the original repository:
   ```bash
   git remote add upstream https://github.com/sarathi-sai7/Placement-Preparation.git
   ```

### 2. Keep Your Local Main Synced
Always sync your local `main` branch with the upstream repository before starting any new work:
```bash
git checkout main
git fetch upstream
git merge upstream/main
```

### 3. Create a Feature Branch
Create a new branch for the current week's tasks. Do not work directly on `main` or reuse long-lived personal branches.
* **Format:** `<your-name>/week-<number>`
* **Examples:**
  - `pranaw/week-01`
  - `sarathi/week-01`
  - `akash/week-02`

```bash
git checkout -b <name>/week-<number>
```

### 4. Create and Organize Your Files
* Navigate to the `STUDENTS/` directory.
* If you haven't already, copy the template folder structure from `STUDENTS/example-student/` and rename it to your exact GitHub username:
  ```text
  STUDENTS/
    └── <your-github-username>/
        ├── README.md
        ├── weekly-updates.md
        ├── notes/
        ├── resources/
        ├── seminars/
        └── dsa/
  ```
* Place your solutions, notes, and progress logs strictly within these directories.

### 5. Commit Your Changes
Use meaningful and professional commit messages.
* **Format:** `type(student-username): brief description`
* **Types:**
  - `feat` (new additions: e.g. adding week 1 DSA solutions)
  - `docs` (updating readme, notes, or weekly updates log)
  - `refactor` (cleaning up or restructuring your code/notes)
* **Examples:**
  - `feat(pranaw): add week-01 DSA solutions`
  - `docs(sarathi): update weekly progress tracker for week 01`

```bash
git add STUDENTS/<your-github-username>/
git commit -m "feat(<your-username>): add week-01 notes and DSA progress"
```

### 6. Push and Open a Pull Request
1. Push your branch to your origin (your fork):
   ```bash
   git push origin <name>/week-<number>
   ```
2. Navigate to the main repository: [https://github.com/sarathi-sai7/Placement-Preparation](https://github.com/sarathi-sai7/Placement-Preparation)
3. You will see a prompt to open a Pull Request. Click on **Compare & pull request**.
4. Fill out the Pull Request template completely (the template will load automatically).
5. Link any related issues or weekly task cards.

### 7. Review and Merge
* An administrator or designated peer will review your PR.
* Address any review feedback by making commits on the same branch and pushing them.
* Once approved and merged, delete your branch from GitHub and locally:
  ```bash
  git checkout main
  git pull upstream main
  git branch -d <name>/week-<number>
  ```

---

## 📜 Code of Conduct & Best Practices

1. **Be Respectful:** Treat peers with kindness in PR comments and discussions.
2. **Help Others:** If someone requests a peer review, take 5 minutes to review their solutions, offer constructive feedback, and point out potential optimizations.
3. **No Code Plagiarism:** Plagiarism defeats the purpose of learning. Writing your own notes and solving the problems yourself is crucial for preparation.
4. **Code Quality:** In your `dsa/` directory, comment your code to explain your logic. Avoid uploading uncommented, messy code.

---

## 🛠️ Git Crisis Management (Troubleshooting)

When working with 45 contributors, Git issues are bound to happen. Here is how to fix the most common mistakes:

### 1. "I accidentally committed to `main` instead of a feature branch!"
If you haven't pushed yet, you can easily move your changes to a new branch:
```bash
# 1. Create a new branch with your changes
git branch <your-name>/week-<number>

# 2. Reset the local main branch to match the origin
git reset HEAD~1 --hard

# 3. Switch to your new branch to continue working
git checkout <your-name>/week-<number>
```

### 2. "My Pull Request has Merge Conflicts!"
This happens when another student's PR was merged first, modifying files you are also editing.
```bash
# 1. Sync your local main first
git checkout main
git pull upstream main

# 2. Switch back to your feature branch
git checkout <your-branch-name>

# 3. Merge main into your branch
git merge main

# 4. Open the conflicted files in VS Code. Resolve conflicts manually by picking the correct blocks.
# 5. Add, commit, and push the resolved files:
git add .
git commit -m "chore: resolve merge conflicts"
git push origin <your-branch-name>
```

### 3. "I want to undo my last commit message or edit the files in it!"
If you made a commit but forgot to add a file or made a typo:
```bash
# Undo the commit but keep all your changes unstaged
git reset HEAD~1
```

### 4. "My fork is out of sync and behind upstream/main!"
Run these commands to catch up your fork's main branch with the main repository:
```bash
git checkout main
git fetch upstream
git merge upstream/main
git push origin main
```

---

> [!WARNING]
> Please do not commit massive binary files, PDFs, or compiled executables. Keep resources in text-based formats (like `.md`, `.cpp`, `.java`, `.py`) and link external PDFs/videos using URLs.

