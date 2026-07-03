# Contributing to DSA - Data Structure and Algorithm Concepts 🧠

Thank you for your interest in contributing! This repository serves as an educational resource for clean, dependency-free C++ implementations of core DSA concepts from scratch.

 We warmly welcome contributors to **introduce entirely new data structures or algorithms** that are not yet part of this repository (e.g., Graphs, Tries, Heaps, Sorting Algorithms, AVL Trees, etc.)!

---

## 🗺️ Table of Contents
- [Code Style & Standards](#-code-style--standards)
- [Directory Structure Guidelines](#-directory-structure-guidelines)
- [How to Add an Implementation](#-how-to-add-an-implementation)
- [Step-by-Step GitHub Workflow](#-step-by-step-github-workflow)
- [Pull Request Checklist](#-pull-request-checklist)

---

## 🎨 Code Style & Standards
To keep the code clear and highly educational for everyone, please follow these guidelines:
* **Object-Oriented**: Implement data structures within self-contained classes (e.g., `class BinarySearchTree`, `class Queue`).
* **Readable Names**: Use explicit, descriptive names for pointers and variables (e.g., `head`, `tail`, `newNode`, `temp`) instead of single letters.
* **Separation of Files**: Keep the implementation logic in its own file (e.g., `queue.cpp`) and write a separate driver test file containing the `main()` function (e.g., `testQueue.cpp`).
* **Complexity Comments**: Include a brief comment above key methods stating their time and space complexity (e.g., `// Time: O(log n) | Space: O(1)`).

---

## 📂 Directory Structure Guidelines

### 🚨 Crucial Rule: No Binary Files
* Do **NOT** commit compiled files like **`a.out`**, `.exe`, or build artifacts.
* Keep your workspace clean by ensuring these files are left out of your git staging area.

### Directory Schema
If you are adding a completely **new data structure or algorithm category**, feel free to create a new folder using **PascalCase** (e.g., `Graph/`, `SortingAlgorithms/`). Otherwise, match the existing folders:
* `BST/` — Tree architectures and test drivers.
* `LinkedList/` — Singly, Doubly, and Circular list structures.
* `Queue/` — FIFO structures including Simple, Circular, and Double-Ended Queues.
* `Stack/` — LIFO variants and stack applications (e.g., expression parsing).
* `SearchingAlgorithms/` — Standard array lookups and search mechanisms.

---

## 🚀 How to Add an Implementation

### 1. File Naming Rules
* Use **camelCase** for source files and test drivers to stay consistent with the repository style (e.g., `priorityQueue.cpp` and `testPriorityQueue.cpp`).
* Match prefixes where applicable (e.g., name test runners starting with lowercase `test` followed by the structure name).

### 2. Pair Requirements
Whether you are extending an old category or introducing a new structure, provide two separate files:
1. `structureName.cpp` — Struct definition, class structure, and helper methods.
2. `testStructureName.cpp` — The driver script with a `main()` function containing tests for edge cases (e.g., checking underflow/overflow conditions).

---

## 💻 Step-by-Step GitHub Workflow

### 1. Fork the Repository
Click here to land directly on the fork page: [Fork this Repository](https://github.com/aamir-m-codes/DSA-concepts/fork) *(Note: Fork create the copy of this repository in your account)*.

### 2. Clone Your Fork
Clone your newly forked repository down to your local computer:
```bash
git clone https://github.com/aamir-m-codes/DSA-concepts.git
cd DSA-concepts
```

### 3. Make Your Changes
Open the folder in your favorite code editor (like VS Code). Add your new C++ data structure files or fix existing ones directly!

### 4. Compile and Local Testing
Verify that your C++ code compiles cleanly without any errors or warning flags before adding it:
```bash
g++ test.cpp -o test # change the output file (e.g test) on your choice
./test.exe
```

### 5. Commit and Push Your Changes
Stage your changes carefully (making sure **not** to include `exe files`), save them with a descriptive message, and push them up to your GitHub profile:
```bash
git add .
git commit -m "feat: add priority queue implementation and test code"
git push origin master
```
---

## 📋 Pull Request Checklist
Before submitting your Pull Request, ensure you have ticked all of these:
1. [ ] Code compiles and executes smoothly with no errors.
2. [ ] Test scripts cover basic operations as well as edge cases.
3. [ ] No `exe` files have been staged or added to the commit.
4. [ ] The primary `README.md` structure outline has been updated if you introduced a completely new file or directory.

---
*Maintained with 💻 by [@aamir-m-codes](https://github.com/aamir-m-codes)*
