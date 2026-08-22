# Data Structures & Algorithms Practice (C++)

Welcome to the **DSA_Practice** repository! This project documents my journey through fundamental and advanced **Data Structures and Algorithms (DSA)** implemented from scratch using **modern C++**.

It builds directly upon object-oriented design principles, custom dynamic memory management, templates, and STL integration.

---

## 🎯 Learning Objectives

* **Algorithmic Efficiency:** Master Big-O notation ($\mathcal{O}$), analyzing time and space complexity for all implementations.
* **Core Data Structures:** Build dynamic linear and non-linear data structures from scratch (Linked Lists, Stacks, Queues, Trees, Graphs).
* **Algorithmic Strategies:** Implement key searching, sorting, recursion, greedy, and dynamic programming patterns.
* **Production Quality:** Write modular, memory-safe, and clean C++ code.

---

## 📂 Repository Structure

| Topic   | Category           | Description                                                  |
| :---    | :---               | :---                                                         |
| **014** | Analysis           | Time & Space Complexity (Big-O Notation)                     |
| **015** | Linear DS          | Dynamic Arrays & Resizing Mechanics                          |
| **016** | Linear DS          | Singly & Doubly Linked Lists                                 |
| **017** | Linear DS          | Stacks & Queues (Custom & STL)                               |
| **018** | Sorting/Searching  | Binary Search & $\mathcal{O}(N \log N)$ Sorting Algorithms   |
| **019** | Trees              | Binary Search Trees (BST) & Traversals                       |
| **020** | Trees              | Balanced Trees (AVL / Heaps) & Priority Queues               |
| **021** | Hashing            | Hash Tables & Collision Resolution                           |
| **022** | Graphs             | Graph Representations, BFS & DFS                             |
| **023** | Advanced           | Recursion, Backtracking & Dynamic Programming                |

---

## Topics

### Topic 14: Time & Space Complexity Analysis
* **File:** [`topic014_complexity.cpp`](topic014_complexity.cpp)
* **Requirements:**
  1. Analyze algorithmic growth rates using Big-O ($\mathcal{O}$) notation.
  2. Implement and compare $\mathcal{O}(N^2)$ brute-force vs $\mathcal{O}(N \log N)$ two-pointer search strategies.
  3. Evaluate time vs. space complexity trade-offs in algorithm design.

---

### Topic 15: Dynamic Arrays & Resizing Mechanics
* **File:** [`topic015_dynamic_array.cpp`](topic015_dynamic_array.cpp)
* **Requirements:**
  1. Build a custom template dynamic vector from raw heap pointers.
  2. Implement capacity doubling for amortized $\mathcal{O}(1)$ push operations.
  3. Manage dynamic array allocation, element access (`operator[]`), and destruction.

---

## 🛠️ How to Compile & Run

All implementations are compiled using `g++` with standard warning flags enabled:

```bash
# Compile single file topic
g++ -std=c++17 -Wall topic014_complexity.cpp -o app

# Run binary (Windows)
.\app.exe

# Run binary (Linux/macOS)
./app
