# Advanced Concurrent Programming - Lab Assignments

This repository contains a collection of laboratory assignments and practical implementations developed for the Advances in Concurrent Programming course. The projects focus on high-performance computing (HPC), multi-core thread synchronization, and memory behavior optimization using C++ and OpenMP.

## 🚀 Key Concepts Covered
Each laboratory assignment targets specific challenges in concurrent execution and hardware-level performance engineering

   Barrier Overhead Performance Measuring the synchronization cost of thread barriers within intensive loops.
   False Sharing Mitigation Analyzing cache-line invalidation and restructuring data types to avoid performance degradation in parallel sections.
   Lock Contention Analysis Benchmarking the performance impact of mutual exclusion using low-level OpenMP locks (`omp_lock_t`).
   Memory Visibility & Synchronization Studying cache coherence and volatile memory behavior between reader and writer threads.
   NUMA-Aware Memory Access Optimizing memory allocation and data access patterns across NUMA (Non-Uniform Memory Access) architectures to minimize latency.

## 🛠️ Tech Stack & Requirements
   Language C++11 or higher
   Parallel Computing Framework OpenMP
   Compiler GCC  G++ (with `-fopenmp` flag enabled)
   OS Environment Linux  Ubuntu

## 💻 How to Compile and Run
To compile any of the lab files (e.g., `false_sharing.cpp`), use the following command in your terminal

```bash
g++ -O3 -fopenmp false_sharing.cpp -o false_sharing
.false_sharing