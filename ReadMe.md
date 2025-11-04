# Task Tracker CLI

A simple command-line app to track tasks — what you need to do, what you're working on, and what you've finished.
This project is designed as a small exercise in filesystem I/O, argument parsing, and building a usable CLI without external libraries.

URL: https://roadmap.sh/projects/task-tracker
---

## Features

* Add, update, and delete tasks
* Mark a task **in-progress** or **done**
* List tasks filtered by status (all / todo / in-progress / done)
* Persist tasks to a `tasks.json` file in the current working directory
* Uses positional command-line arguments only (no interactive prompts required)
* No external dependencies — use your language’s native filesystem and argument parsing

---

## Task model (stored in `tasks.json`)

Each task is an object with these properties:

```json
{
  "id": 1,
  "description": "Buy groceries",
  "status": "todo",          // one of: "todo", "in-progress", "done"
  "createdAt": "2025-10-25T15:12:30Z",
  "updatedAt": "2025-10-25T15:12:30Z"
}
```

`tasks.json` is an array of these task objects. The file should be created automatically if it doesn't exist.

---

## CLI usage (examples)

> Use positional arguments. The first argument is the command, following arguments are as shown.

```bash
# Add a new task
task-cli add "Buy groceries"
# Output:
# Task added successfully (ID: 1)

# Update a task description
task-cli update 1 "Buy groceries and cook dinner"
# Output:
# Task 1 updated

# Delete a task
task-cli delete 1
# Output:
# Task 1 deleted

# Mark a task as in-progress
task-cli mark-in-progress 2
# Output:
# Task 2 marked in-progress

# Mark a task as done
task-cli mark-done 2
# Output:
# Task 2 marked done

# List all tasks
task-cli list

# List tasks by status
task-cli list done
task-cli list todo
task-cli list in-progress
```

Example `task-cli list` output (human-readable):

```
ID  Description                      Status        Created At
1   Buy groceries                    todo          2025-10-25 11:12
2   Write unit tests                 in-progress   2025-10-24 09:07
3   Submit project                   done          2025-10-23 16:20
```

---

## Commands reference

* `add "description"` — create a new task (status defaults to `todo`).
* `update <id> "new description"` — change the description and `updatedAt`.
* `delete <id>` — remove a task permanently.
* `mark-in-progress <id>` — set status to `in-progress`, update `updatedAt`.
* `mark-done <id>` — set status to `done`, update `updatedAt`.
* `list [status]` — show tasks. If `status` is omitted, show all. Allowed statuses: `todo`, `in-progress`, `done`.

Return informative stdout messages and non-zero exit codes on failure (e.g., invalid id, malformed args, filesystem errors).

---

## Implementation notes & constraints

* You may use **any programming language** (Python, JavaScript/Node, Ruby, Go, etc.).
* **Positional arguments only** — do not require flags for the core tasks (e.g. `add`, `update`, `delete`).
* Store data as `tasks.json` in the **current directory**. Create it if missing.
* Use the language’s **native filesystem module** (e.g., `fs` in Node, `open()`/`json` in Python).
* **No external dependencies** or frameworks. Standard library only.
* Handle errors gracefully:

    * Invalid numeric IDs → informative message (e.g., `Task 42 not found`), exit non-zero.
    * Missing arguments → show usage message.
    * Corrupt `tasks.json` → back up the file and create a new, empty store or present helpful message.
* Ensure ID uniqueness. A common approach: store a monotonically-increasing counter (in-memory by scanning max existing `id` + 1) or track next ID in the file.

---

## Suggested implementation roadmap

1. Initialize project and create `tasks.json` if missing (empty array `[]`).
2. Implement `list` (reads file, prints tasks) — quick win for visibility.
3. Implement `add` (create timestamps, assign unique `id`, append, save).
4. Implement `update` and `delete`.
5. Implement `mark-in-progress` and `mark-done`.
6. Add helpful CLI usage/error messages and edge-case handling (invalid JSON, invalid IDs, I/O errors).
7. Test each command and verify `tasks.json` contents match expected results.

---

## Tips & edge cases

* Use ISO 8601 timestamps (e.g., `2025-10-25T15:12:30Z`) for `createdAt`/`updatedAt`.
* When deleting tasks, you can either remove the entry or mark it with a `deleted` flag — spec expects removal.
* If multiple processes might modify `tasks.json`, consider simple file locking or retry logic to avoid race conditions. (Optional for this exercise.)
* Keep output machine- and human-friendly: consider adding an optional `--json` output mode later (not required).

---

## Testing

* Manually verify commands by running them and inspecting `tasks.json`.
* Example test cases:

    * Add two tasks, update the first, mark second done, list `done` shows only the second.
    * Attempt to update a non-existent ID → returns error and exit code ≠ 0.
    * Corrupt `tasks.json` and ensure your app detects and handles it gracefully.

---

## Example `tasks.json` (after a few operations)

```json
[
  {
    "id": 1,
    "description": "Buy groceries",
    "status": "todo",
    "createdAt": "2025-10-25T11:12:00Z",
    "updatedAt": "2025-10-25T11:12:00Z"
  },
  {
    "id": 2,
    "description": "Write unit tests",
    "status": "in-progress",
    "createdAt": "2025-10-24T09:07:30Z",
    "updatedAt": "2025-10-25T12:00:00Z"
  }
]
```

---

## Stretch goals (optional)

* Add sorting options (by `createdAt`, `updatedAt`, `status`).
* Add priority field (`low`, `medium`, `high`).
* Add tags and a `filter` command (e.g., `task-cli list todo --tag=home`).
* Implement search (`task-cli find "grocer"`).
* Support colored terminal output for status (requires considering dependency policy — not required).

---

## Contributing & license

This repo is a practice project — contributions are welcome. Add clear commit messages and tests for new features. Use a permissive license (e.g., MIT) if you plan to publish it.

---

## Final words

This is a compact, practical project that covers argument parsing, file I/O, error handling, and a tiny bit of UX design for the terminal. Build it incrementally — start small, make it robust, then iterate.

Happy coding! 🚀
