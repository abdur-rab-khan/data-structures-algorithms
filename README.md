# ![image](https://img.icons8.com/?size=50&id=Y2pl5tCeyxJm&format=png&color=000000) Data Structures and Algorithms

> "Algorithms are the poetry of computation. Just like verse in a poem, the code has rhythm, and meaning beyond the simple arrangement of characters." — Marijn Haverbeke

> "The difference between a bad programmer and a good one is whether they consider their code or their data structures more important. Bad programmers worry about the code. Good programmers worry about data structures and their relationships." — Linus Torvalds

> "Computer science is no more about computers than astronomy is about telescopes." — Edsger W. Dijkstra

## Overview

This repository contains implementations, explanations, and examples of common data structures and algorithms. These are fundamental building blocks for creating efficient solutions to computational problems.

## Data Structures

### 1. String
- Implementation of string manipulation techniques
- Pattern matching
- String hashing
- Suffix arrays and trees
- LCP (Longest Common Prefix) arrays

### 2. Array
- Static and dynamic arrays
- Matrix operations
- Circular arrays
- Sparse arrays
- Kadane's algorithm and sliding window techniques

### 3. Linked List
- Singly linked list
- Doubly linked list
- Circular linked list
- Skip list
- XOR linked list (memory efficient)

### 4. Stack
- Array-based implementation
- Linked list-based implementation
- Applications: 
  - Expression evaluation
  - Syntax parsing
  - Backtracking algorithms
  - Function call management

### 5. Queue
- Array-based implementation
- Linked list-based implementation
- Circular queue
- Double-ended queue (Deque)
- Priority queue
- Applications in BFS and scheduling

### 6. Tree
- Binary tree
- Binary search tree (BST)
- AVL tree
- Red-black tree
- B-tree and B+ tree
- Segment tree
- Trie (Prefix tree)
- Fenwick tree (Binary Indexed Tree)
- N-ary tree

### 7. Heap
- Min heap
- Max heap
- Binomial heap
- Fibonacci heap
- Implementation techniques
- Applications in priority scheduling

### 8. Graph
- Adjacency matrix
- Adjacency list
- Incidence matrix
- Edge list
- Directed and undirected graphs
- Weighted graphs
- Bipartite graphs
- DAGs (Directed Acyclic Graphs)

### 9. Hash Table
- Direct addressing
- Chaining
- Open addressing
  - Linear probing
  - Quadratic probing
  - Double hashing
- Perfect hashing
- Consistent hashing
- Bloom filters

### 10. Advanced Data Structures
- Disjoint Set (Union-Find)
- Treap
- Splay tree
- KD-tree
- Quadtree
- Sparse table
- Suffix automaton

## Algorithms

### 1. String Algorithms
- Pattern matching
  - Naive approach
  - KMP (Knuth-Morris-Pratt)
  - Rabin-Karp
  - Boyer-Moore
  - Z algorithm
- Edit distance (Levenshtein distance)
- Longest common subsequence
- Manacher's algorithm (palindromes)
- Suffix arrays and LCP

### 2. Sorting
- Comparison-based sorting
  - Bubble sort
  - Selection sort
  - Insertion sort
  - Merge sort
  - Quicksort
  - Heapsort
  - Shell sort
- Non-comparison sorting
  - Counting sort
  - Radix sort
  - Bucket sort
- Hybrid algorithms (Timsort, Introsort)
- External sorting algorithms

### 3. Searching
- Linear search
- Binary search
- Ternary search
- Jump search
- Interpolation search
- Exponential search
- Hash-based searches
- Searching in trees and graphs

### 4. Dynamic Programming
- Memoization vs. tabulation
- Common problems:
  - Fibonacci sequence
  - Knapsack problem
  - Longest increasing subsequence
  - Matrix chain multiplication
  - Edit distance
  - Coin change problem
  - Longest common subsequence
- State reduction techniques
- Optimization methods

### 5. Greedy Algorithms
- Activity selection
- Huffman coding
- Prim's algorithm
- Kruskal's algorithm
- Dijkstra's algorithm
- Fractional knapsack
- Job sequencing
- Interval scheduling

### 6. Graph Algorithms
- Traversals
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
- Shortest path algorithms
  - Dijkstra's algorithm
  - Bellman-Ford algorithm
  - Floyd-Warshall algorithm
  - Johnson's algorithm
- Minimum Spanning Tree
  - Prim's algorithm
  - Kruskal's algorithm
- Strongly Connected Components
  - Kosaraju's algorithm
  - Tarjan's algorithm
- Topological sort
- Bipartite checking
- Maximum flow
  - Ford-Fulkerson algorithm
  - Edmonds-Karp algorithm
  - Dinic's algorithm
- Matching algorithms
- Articulation points and bridges

### 7. Tree Algorithms
- Tree traversals (preorder, inorder, postorder, level-order)
- Lowest Common Ancestor (LCA)
- Diameter of a tree
- Path sum problems
- Binary search tree operations
- Balanced trees maintenance
- Heavy-light decomposition
- Centroid decomposition

### 8. Recursion & Backtracking
- Recursive function principles
- Tail recursion
- Backtracking framework
- Common problems:
  - N-Queens
  - Sudoku solver
  - Hamiltonian path
  - Subset sum
  - Permutations and combinations
  - Graph coloring
- Pruning techniques

### 9. Divide and Conquer
- Master theorem
- Binary search
- Merge sort
- Quicksort
- Strassen's matrix multiplication
- Closest pair of points
- Karatsuba algorithm for multiplication
- Fast Fourier Transform (FFT)

### 10. Linked List Algorithms
- Traversal techniques
- Reversal (iterative and recursive)
- Cycle detection (Floyd's algorithm)
- Merge two sorted lists
- Finding middle element
- Intersection detection
- Deep copy with random pointers

### 11. Bit Manipulation Algorithms
- Basic operations (set, clear, flip, check bits)
- Power of two checks
- Counting set bits
- Bitwise tricks
- Bit masks
- Gray code
- Subset generation
- XOR applications

### 12. Heap and Priority Queue Algorithms
- Heap construction
- Heapify procedure
- Heap sort
- Priority queue operations
- Median maintenance
- Merge K sorted arrays
- Sliding window maximum

### 13. Randomized Algorithms
- Random sampling
- Monte Carlo algorithms
- Las Vegas algorithms
- Randomized quicksort
- Karger's algorithm
- Skip lists
- Reservoir sampling

### 14. Numerical Algorithms
- GCD and LCM
- Prime generation (Sieve of Eratosthenes)
- Modular arithmetic
- Matrix operations
- Fast exponentiation
- Chinese remainder theorem
- Number theoretic transforms

### 15. Computational Geometry
- Convex hull algorithms
  - Graham scan
  - Jarvis march
  - Quick hull
- Line intersection
- Closest pair of points
- Point in polygon
- Geometric sweeping
- Voronoi diagrams

## Resources

### Books
- "Introduction to Algorithms" by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
- "Algorithms" by Robert Sedgewick and Kevin Wayne
- "The Algorithm Design Manual" by Steven S. Skiena
- "Competitive Programming" by Steven Halim and Felix Halim
- "Data Structures and Algorithms Made Easy" by Narasimha Karumanchi

### Online Platforms
- LeetCode
- HackerRank
- Codeforces
- GeeksforGeeks
- TopCoder
- SPOJ
- AtCoder

### Courses
- MIT OpenCourseWare - Introduction to Algorithms
- Stanford Algorithms Specialization (Coursera)
- Princeton Algorithms (Coursera)
- Data Structures and Algorithms Specialization (Coursera)

## Contributing

Contributions to improve implementations, add new algorithms, or enhance documentation are always welcome. Please feel free to submit a pull request.

## License

[Include your preferred license here]
