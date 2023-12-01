# OS HW2
# Banker's Algorithm for Deadlock Avoidance

This C++ program implements the Banker's algorithm for deadlock avoidance in a system with multiple processes and resources. The program reads input data from a file, checks if the system is in a safe state, and provides the safe sequence if applicable.

## Table of Contents
- [Introduction](#introduction)
- [Usage](#usage)
- [Input Format](#input-format)
- [Output](#output)
- [Example](#example)
- [Author](#author)

## Introduction

The Banker's algorithm is a deadlock avoidance algorithm used in operating systems to ensure that the system remains in a safe state by carefully allocating and releasing resources.

## Usage

1. **Compile the Code:**
    ```bash
    g++ -o bankers_algorithm code.cpp
    ```

2. **Run the Program:**
    ```bash
    ./bankers_algorithm
    ```

## Input Format

Create an input file (`input.txt`) with the following format:
A, B, C A, B, C A, B, C
P0 0 1 0 7 5 3 3 3 2
P1 2 0 0 3 2 2
P2 3 0 2 9 0 2
P3 2 1 1 2 2 2
P4 0 0 2 4 3 3


Each line represents a process, and the values are space-separated. The first three values on each line represent the current allocation of resources (A, B, C) to that process. The next three values represent the maximum resources (A, B, C) that the process may request. The final three values represent the available resources (A, B, C) in the system.

## Output

The program will output whether the system is in a safe state or not. If it is in a safe state, it will display the safe sequence of processes.
Output is in result.png file.

