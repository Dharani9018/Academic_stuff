# U1:
## Euclid's Algo
## Sequential Search
## Non Recursive:
- Max element
- Unique element
- Matrix Mutiplication
- Gaussian Elemination
- 

# A. Transform and Conquer:
- *make the problem easier before solving it.*
## 3 Types:
### 1. Instance Simplification:
- same problem, but simpler input
- ex: sort first -> then solve.
### 2. Representation Change:
- same problem, different structure
- better structure = faster operations
### 3. Problem Reduction:
- Convert into another known problem and solve that instead.
## Pre-Sorting: First sort, then solve
### Classic Problems:
#### 1. Element uniqueness:
- Brute force
  - compare all pairs
  - Time = theta(n^2)
- Presorting
  - sort theta(nlog)
  - compare adjacent: theta(n)
  - final : theta(nlog(n))
#### 2. Mode
- Brute force:
  - Count frequencies manually
  - Worst case - all distinct
  - Comparisions: n(n-1)/2
```C
algo mode(a[0..n-1])
  maxcount <- 0
  mode <- a[0]
  for i = 0 to n-1 do
    count <- 0
    for j = i + 1 to n-1 do
      if a[i] = a[j]
        count <- count + 1
    
    if(maxcount<count)
      maxcount <- count
      mode <- a[i]
  return mode
```
- Pre-sort:
  - sort
  - compare consecutive equal elements
```C
algo mode(a[0..n-1])
  sort(a[0..n-1])
  mode <- a[0]
  maxcount <- 1
  count <- 1
  for i <- 1 to n-1 do
    if a[i] = a[i-1]
      count <- count + 1;
    else
      if maxcount < count then
        maxcount <- count
        mode = a[i-1]
      count <- 1
  if maxcount < count then
    mode <- a[n-1]
  return mode
```
#### 3. Closest pair: Given an array of numbers, find the two elements with the smallest difference between them.
- Brute force:
  - Time = theta(n^2)
```C
algo ClosestPair(a[0..n-1])
  e1 <- a[0]
  e2 <- a[1]
  diference <- p1-p2
  for i = 0 to n-2
    for j = i + 1 to n-1
      if a[i] - a[j] < difference
        difference <- a[i] - a[j]
        e1 <- a[i]
        e2 <- a[j]
  return (e1,e2);
```

- Presort:
  - sort 
  - Compare adjacent elements
  - time = theta(n(log(n)))
```C
algo ClosestPair(a[0..n-1])
  sort(a[0..n-1])
  e1 <- a[0]
  e2 <- a[1]
  difference <- a[1] - a[0]
  for i = 1 to n-1 do
    if a[i] - a[i-1] < difference
      difference <- a[i] - a[i-1]
      e1 <- a[i]
      e2 <- a[i-1]
  return (e1,e2)
```
## For Presorting: Sorting always dominates
```C
T(n) = T(sort) + T(scan)
     = Θ(n log n) + Θ(n)
     = Θ(n log n)
```
---
# B. Heaps and Heap Sort:
## 1. Heap tree
- Shape property: Complete binary tree
  - left to right filling
  - all levels are filled completely except for the last.
- Heap property: Parent>= child (max heap), root node -> max element
- Height = log₂(n)
- Array representation:
  - for index i ->
  - parent = i/2
  - left child = i*2
  - right child = i * 2 + 1
## 2. Heapify : Fix violation by pushing the element down
### Steps:
#### 1. Compare with children
#### 2. pick a larger child
#### 3. Swap if need
#### 4. Continue down
##### Time: theta(log(n))
## 3. Building Heap:
### A. Botton up heap:
#### From the last non - leaf apply heapify upwards
#### Start from n/2 to 1
#### **`Time : theta(n)`**


