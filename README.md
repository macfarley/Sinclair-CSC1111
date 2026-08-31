# Sinclair-CSC1111

Coursework and activities for CSC 1111 (Intro to C++) at Sinclair Community College.

This repo is built up incrementally as the class progresses, so it can be pulled
down on the campus computers (Visual Studio 2022 on Windows) as well as worked
on from other machines/editors (e.g. VS Code on Linux/Mac).

## Working on campus (Visual Studio 2022, Windows)

1. Clone the repo:
   ```
   git clone https://github.com/<your-username>/Sinclair-CSC1111.git
   ```
2. Open Visual Studio 2022 → **File > Open > Folder...** and select the cloned
   folder (or create/open a `.sln` if the assignment calls for a full project).
3. Individual `.cpp` files can be run without a project via **File > Open >
   File...** then **Ctrl+F5** (Run Without Debugging), or add them to a
   Console App project.
4. Before leaving, commit and push your changes:
   ```
   git add .
   git commit -m "describe what you did"
   git push
   ```

## Working elsewhere (VS Code, g++, etc.)

```bash
g++ -std=c++17 path/to/file.cpp -o path/to/file
./path/to/file
```

## Structure

- `Activities/` — in-class activities, exercises, and notes.

## Notes

Build artifacts, binaries, and Visual Studio's per-user/project cruft
(`.vs/`, `bin/`, `obj/`, `*.exe`, etc.) are excluded via `.gitignore` — only
source files and notes should be committed.
