# Linked List

This folder contains **linked list implementations** in different programming languages (C, C++, Python).

---

## 📌 What is a Linked List?
A **linked list** is a linear data structure where elements (called **nodes**) are connected using **pointers/references** instead of being stored in continuous memory like arrays.

Each node contains:
- **Data** → The value stored
- **Pointer/Reference** → Link to the next node (and sometimes the previous node)

---

## 📂 Implementations
- `C/linkedlist.c` → Singly linked list using pointers  
- `C++/linkedlist.cpp` → Singly linked list using classes  
- `Python/linkedlist.py` → Singly linked list using objects  

*(Optional: Add doubly and circular linked list versions later)*

---

## ⚡ Operations Implemented
- **Insertion**  
  - At the beginning  
  - At the end  
  - At a specific position  

- **Deletion**  
  - From beginning  
  - From end  
  - From a given position  

- **Traversal** → Display all elements  
- **Search** → Find an element in the list  
- **Reverse** (bonus)  

---

## 🔎 Time Complexity
| Operation       | Complexity |
|-----------------|------------|
| Insertion       | O(1) at head, O(n) at end/position |
| Deletion        | O(1) at head, O(n) at end/position |
| Traversal       | O(n) |
| Search          | O(n) |

---

## 🎯 Real-World Applications
- Implementing stacks and queues  
- Browser forward/backward navigation  
- Music playlist navigation  
- Undo/redo in text editors  
- Graph adjacency lists representation  

---