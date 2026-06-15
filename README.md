# ShieldNet

## Cybersecurity Management System Powered by Data Structures & Algorithms

*A console-based cybersecurity simulator where every module demonstrates a real-world security operation using a fundamental Data Structure or Algorithm.*

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-brightgreen)
![Build](https://img.shields.io/badge/Build-Passing-success)
![DSA Project](https://img.shields.io/badge/Project-DSA%20Semester%20Project-purple)

![Stack](https://img.shields.io/badge/Stack-SecurityUndo-blue)
![Queue](https://img.shields.io/badge/Queue-AlertLine-green)
![Trie](https://img.shields.io/badge/Trie-ThreatDictionary-red)
![Graph](https://img.shields.io/badge/Graph-NetworkMap-orange)
![Dijkstra](https://img.shields.io/badge/Algorithm-Dijkstra-yellow)

</div>

---

# Overview

ShieldNet is a cybersecurity management simulator developed as a Data Structures & Algorithms project.

The system demonstrates how fundamental DSA concepts can be applied to real-world cybersecurity operations such as:

- Managing security changes
- Processing security alerts
- Blocking malicious IPs
- Prioritizing threats
- Modeling computer networks
- Finding attack paths
- Planning security patches
- Detecting threat signatures

Each module is powered by a specific Data Structure or Algorithm, making the project both a cybersecurity simulation and a practical DSA learning platform.

---

# Features & Data Structures

| # | Module | Data Structure / Algorithm | Purpose |
|---|---------|---------------------------|---------|
| 1 | Security Undo | Stack | Reverse recent security actions |
| 2 | Alert Line | Queue | Process alerts in arrival order |
| 3 | IP Blocker | Binary Search | Fast blocked IP lookup |
| 4 | Danger Sorter | Max Heap (Priority Queue) | Prioritize threats by severity |
| 5 | Network Map | Graph (Adjacency List) | Model network devices and links |
| 6 | Weakest Link | Dijkstra Algorithm | Find shortest attack path |
| 7 | Patch Planner | Greedy Strategy | Prioritize critical updates |
| 8 | Threat Dictionary | Trie | Fast threat-signature matching |

---

# Project Architecture

```text
                SHIELDNET

        ┌─────────────────────┐
        │      Main Menu      │
        └─────────────────────┘

          │
          ├── Security Undo
          ├── Alert Line
          ├── IP Blocker
          ├── Danger Sorter
          ├── Network Map
          ├── Weakest Link
          ├── Patch Planner
          └── Threat Dictionary
```

Network Map provides graph data used by Weakest Link Analysis.

---

# 2.1 Project Title

**ShieldNet – Cybersecurity Management System Using Data Structures and Algorithms**

---

# 2.2 Problem Statement

Modern organizations generate large volumes of security events, network activities, and threat information. Managing these operations efficiently requires structured storage, fast searching, prioritized processing, and intelligent path analysis.

The objective of ShieldNet is to simulate a cybersecurity environment while demonstrating how Data Structures and Algorithms can be used to solve practical security problems.

---

# 2.3 Objectives

- Demonstrate real-world applications of DSA.
- Simulate cybersecurity operations.
- Implement multiple data structures in one integrated project.
- Analyze efficiency using time complexity.
- Provide an interactive console-based interface.

---

# 2.4 System Overview / Architecture

The system consists of eight independent cybersecurity modules.

1. Security Undo maintains action history.
2. Alert Line processes incoming alerts.
3. IP Blocker stores and searches blocked IPs.
4. Danger Sorter prioritizes alerts.
5. Network Map models devices and connections.
6. Weakest Link analyzes attack paths.
7. Patch Planner schedules updates.
8. Threat Dictionary performs signature matching.

---

# 2.5 Data Structures and Algorithms Used

## Stack

**Used in:** Security Undo

**Operations:**
- Push
- Pop
- Top

**Time Complexity:**
- Push: O(1)
- Pop: O(1)

---

## Queue

**Used in:** Alert Line

**Operations:**
- Enqueue
- Dequeue

**Time Complexity:**
- Enqueue: O(1)
- Dequeue: O(1)

---

## Binary Search

**Used in:** IP Blocker

**Time Complexity:**
- Search: O(log n)

---

## Max Heap (Priority Queue)

**Used in:** Danger Sorter

**Purpose:**
- Prioritize security alerts based on severity

**Operations:**
- Insert Alert
- Retrieve Highest Priority Alert

**Time Complexity:**
- Insert: O(log n)
- Highest Priority Alert: O(1)
- Remove Highest Priority Alert: O(log n)

---

## Graph

**Used in:** Network Map

**Representation:**
- Adjacency List

---

## Dijkstra Algorithm

**Used in:** Weakest Link

**Purpose:**
- Find shortest attack path

**Time Complexity:**
- O((V + E) log V)

---

## Greedy Strategy

**Used in:** Patch Planner

**Purpose:**
- Patch highest-risk devices first

---

## Trie

**Used in:** Threat Dictionary

**Purpose:**
- Prefix-based threat signature detection

**Time Complexity:**
- Insert: O(L)
- Search: O(L)

---

# 2.6 Implementation Approach

1. Design modules based on cybersecurity operations.
2. Assign an appropriate DSA to each module.
3. Implement classes using Object-Oriented Programming.
4. Integrate modules through a central menu system.
5. Add sample datasets for testing.
6. Validate functionality through user interaction.

---

# 2.7 Time and Space Complexity Analysis

| Module | Complexity |
|----------|------------|
| Security Undo | O(1) |
| Alert Line | O(1) |
| IP Blocker Search | O(log n) |
| Danger Sorter | O(log n) |
| Network Map | O(V + E) |
| Weakest Link | O((V + E) log V) |
| Patch Planner | O(n log n) |
| Threat Dictionary | O(L) |

---

# 2.8 Execution Steps

## Compile

```bash
g++ main.cpp \
Source/SecurityUndo.cpp \
Source/AlertLine.cpp \
Source/IPBlocker.cpp \
Source/DangerSorter.cpp \
Source/NetworkMap.cpp \
Source/WeakestLink.cpp \
Source/PatchPlanner.cpp \
Source/ThreatDictionary.cpp \
-o shieldnet
```

## Run

```bash
./shieldnet
```

### Windows

```bash
shieldnet.exe
```

---

# 2.9 Sample Inputs and Outputs

## Threat Dictionary

### Input

```text
hacker123
```

### Output

```text
Threat Signature Detected: hack
```

---

## IP Blocker

### Input

```text
192.168.1.25
```

### Output

```text
IP BLOCKED
```

---

## Weakest Link

### Input

```text
Source: Laptop
Destination: Database
```

### Output

```text
Laptop -> Router -> Server -> Database

Total Cost = 7
```

---

# 2.10 Screenshots

## 1. Main Menu

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/6d97bc09-543f-434e-a95a-a863585bcb49" />
<br>
<b>Figure 1:</b> Main Menu Interface
</td>
</tr>
</table>

---

## 2. Security Undo

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/f893ee76-12e9-44db-8cec-80d5f78f4880" />
<br>
<b>Figure 2:</b> Security Undo Module
</td>
</tr>
</table>

---

## 3. Alert Line

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/bc5dba07-0d1b-438e-926e-166381312700" />
<br>
<b>Figure 3:</b> Alert Line Module
</td>
</tr>
</table>

---

## 4. IP Blocker

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/0438c159-24f7-4e1a-947c-cb2f116a1b04" />
<br>
<b>Figure 4:</b> IP Blocker Module
</td>
</tr>
</table>

---

## 5. Danger Sorter

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/6c966cb8-389d-4ebd-a351-63ec3078a298" />
<br>
<b>Figure 5:</b> Danger Sorter Module
</td>
</tr>
</table>

---

## 6. Network Map

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/ed76a8cc-db46-4c7d-8ca1-b44252742141" />
<br>
<b>Figure 6:</b> Network Map Module
</td>
</tr>
</table>

---

## 7. Weakest Link

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/884d2a44-c28b-4571-b67b-9b059061df01" />
<br>
<b>Figure 7:</b> Weakest Link Analysis Module
</td>
</tr>
</table>

---

## 8. Patch Planner

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/2560c919-b5d2-48d3-9b7a-332ec86af05a" />
<br>
<b>Figure 8:</b> Patch Planner Module
</td>
</tr>
</table>

---

## 9. Threat Dictionary

<table>
<tr>
<td align="center">
<img width="700" src="https://github.com/user-attachments/assets/2c41276c-bba7-456f-8322-64c3f054334f" />
<br>
<b>Figure 9:</b> Threat Dictionary Module
</td>
</tr>
</table>

---

# 2.11 Results and Observations

- All modules performed successfully.
- DSA concepts mapped effectively to cybersecurity operations.
- Binary Search significantly reduced IP lookup time.
- Trie enabled efficient threat signature detection.
- Dijkstra accurately identified shortest attack paths.
- Greedy prioritization improved patch planning.
 - Max Heap efficiently prioritized high-severity security alerts.

---

# 2.12 Conclusion

ShieldNet successfully demonstrates how Data Structures and Algorithms can be applied to cybersecurity management. The project integrates Stack, Queue, Binary Search, Max Heap, Graphs, Dijkstra Algorithm, Greedy Strategy, and Trie into a unified system that simulates real-world security operations while reinforcing core DSA concepts.

---

# Project Structure

```text
ShieldNet/
├── Headers/
│   ├── SecurityUndo.h
│   ├── AlertLine.h
│   ├── IPBlocker.h
│   ├── DangerSorter.h
│   ├── NetworkMap.h
│   ├── WeakestLink.h
│   ├── PatchPlanner.h
│   └── ThreatDictionary.h
│
├── Source/
│   ├── SecurityUndo.cpp
│   ├── AlertLine.cpp
│   ├── IPBlocker.cpp
│   ├── DangerSorter.cpp
│   ├── NetworkMap.cpp
│   ├── WeakestLink.cpp
│   ├── PatchPlanner.cpp
│   └── ThreatDictionary.cpp
│
├── main.cpp
└── README.md
```

---

# Built With

- C++
- STL
- VS Code
- Git
- GitHub

---

# Author

**Dhruv**

Computer Science Engineering (CSE)

**DSA Semester Project – Cybersecurity Management System**
