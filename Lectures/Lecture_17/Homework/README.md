# Homework

**Q.1** Is bubble sort algorithm stable or unstable?

**Ans :** Bubble sort is generally considered a stable sorting algorithm. In bubble sort, adjacent elements in the list are compared and swapped if they are out of order. Importantly, when two elements have equal values, bubble sort does not swap them, thus preserving their original order. This characteristic ensures that bubble sort is a stable sorting algorithm.

Here's an example to illustrate the stability of bubble sort:

Suppose you have a list of students with their names and exam scores:

```
Alice: 90
Bob: 85
Carol: 90
David: 80
```

If you apply bubble sort to sort this list by exam scores, the result might look like this:

```
David: 80
Bob: 85
Alice: 90
Carol: 90
```

In this sorted list, Alice and Carol, who both scored 90, are still in their original order. Bubble sort does not change the relative order of equal elements, demonstrating its stability.

So, in summary, bubble sort is a stable sorting algorithm, and it preserves the relative order of equal elements in the input data.

**Q.2** what is in place sort?

**Ans :** An `in-place` sorting algorithm is a type of sorting algorithm that sorts a list or array without requiring additional memory space proportional to the size of the input. 

In other words, it sorts the elements directly within the input data structure, without creating a separate copy or using auxiliary data structures. In-place sorting algorithms are particularly valuable when working with large datasets where memory usage is a critical concern.

In-place sorting algorithms have the advantage of not consuming extra memory, but they may require more computational time compared to algorithms that use additional memory for temporary storage. Common in-place sorting algorithms include:

1. __Bubble Sort:__ Bubble sort compares and swaps adjacent elements in the list until the entire list is sorted. It is an in-place sorting algorithm.

2. __Insertion Sort:__ Insertion sort builds the sorted portion of the list one element at a time by inserting each element into its correct position among the already sorted elements. It is also an in-place sorting algorithm.

3. __Selection Sort:__ Selection sort repeatedly selects the minimum (or maximum) element from the unsorted portion of the list and moves it to the sorted portion. Like bubble and insertion sort, it is an in-place sorting algorithm.

4. __Quick Sort:__ Quick sort is a popular and efficient in-place sorting algorithm that uses a divide-and-conquer strategy. It recursively partitions the list into smaller sublists and sorts them in-place.

5. __Heap Sort:__ Heap sort is an in-place comparison-based sorting algorithm that uses a binary heap data structure to efficiently find and remove the minimum (or maximum) element from the unsorted portion of the list.

In-place sorting algorithms are often favored in situations where memory usage is a critical constraint. However, they may not always be the most efficient choice in terms of computational time, especially for very large datasets. The choice of sorting algorithm depends on the specific requirements of the problem and the available resources.

### [GFG Quiz Link](https://www.geeksforgeeks.org/top-mcqs-on-bubblesort-algorithm-with-answers/)
