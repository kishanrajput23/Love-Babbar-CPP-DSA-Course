# Homework

- [Article on Quick Sort](https://www.geeksforgeeks.org/quick-sort/)

**Q.1** Is quick sort in-place algortihm?
**Ans:** 
Yes, QuickSort is an in-place sorting algorithm. An in-place sorting algorithm is one that doesn't require extra memory or storage space proportional to the input size. 

In QuickSort, the partitioning is done in-place, meaning the elements are rearranged within the array itself without requiring additional memory.

The in-place nature of QuickSort is one of its advantages, especially for large datasets where memory usage is a concern. 

However, it's important to note that the recursive nature of QuickSort means that it does use the call stack, and in the worst-case scenario, it can lead to stack overflow for very large datasets. 

This is one reason why there are hybrid sorting algorithms like Introsort that combine QuickSort's efficiency with the worst-case guarantees of other algorithms.

**Q.2** Is quick sort stable algorithm?

**Ans:** QuickSort is not considered a stable sorting algorithm. Stability in sorting algorithms refers to the preservation of the relative order of equal elements. 

In a stable sort, if two elements have equal keys, their relative order in the sorted output is the same as their order in the input.

QuickSort, in its basic form, does not guarantee stability. The partitioning step in QuickSort can change the relative order of equal elements. 

However, there are variations and optimizations of QuickSort that can be made stable, but they usually come with some trade-offs in terms of performance.