# Homework

**Q.1** Draw a flowchart of selection sort algorithm.

![selection-sort](https://github.com/kishanrajput23/Love-Babbar-CPP-DSA-Course/assets/70385488/c697dd3b-142f-4397-bb2c-a3e3ead6c3ce)


**Q.2** What is stable and unstable algorithm?

**Ans :**

__Stable Algorithm:__

- A stable algorithm is one that preserves the relative order of elements with equal keys or values in the input data.
- In sorting algorithms, for example, stability means that if two elements have the same key and appear in a certain order in the input, they will also appear in the same order in the output.
- Stability is often desirable in algorithms when you want to maintain the original order of equal elements or when it's essential to track the history of certain elements.

__Unstable Algorithm:__

- An unstable algorithm does not guarantee the preservation of the relative order of equal elements in the input data.
- In an unstable sorting algorithm, for instance, elements with equal keys may not necessarily retain their original order in the sorted output.
- Unstable algorithms can be more efficient than stable ones in some cases because they do not need to maintain the original order of equal elements.
Here's an example to illustrate stability:

Suppose you have a list of students with their names and exam scores:

```
Alice: 90
Bob: 85
Carol: 90
David: 80
```

If you sort this list by exam scores using a stable sorting algorithm, the output might be:

```
Bob: 85
Alice: 90
Carol: 90
David: 80
```

Notice that Alice and Carol, who both scored 90, retain their original order. This is an example of stability.

If you use an unstable sorting algorithm, the output might be:

```
David: 80
Bob: 85
Alice: 90
Carol: 90
```

In this case, Alice and Carol are not guaranteed to be in the same order as in the original input, which is an example of instability.

The choice of using a stable or unstable algorithm depends on the specific requirements and constraints of a particular problem or application. Stability can be an important consideration in some cases, while in others, performance and efficiency may take precedence.


**Q.3** Is selection sort algorithm stable or unstable?

**Ans :** Selection sort is generally considered an unstable sorting algorithm. In selection sort, the algorithm repeatedly selects the minimum (or maximum) element from the unsorted portion of the list and moves it to the sorted portion. During this process, the relative order of equal elements can change.

Here's an example to illustrate the instability of selection sort:

Suppose you have a list of students with their names and exam scores:

```
Alice: 90
Bob: 85
Carol: 90
David: 80
```

If you apply selection sort to sort this list by exam scores, the result might look like this:

```
David: 80
Bob: 85
Alice: 90
Carol: 90
```

In this sorted list, Alice and Carol, who both scored 90, are no longer in their original order. This demonstrates the instability of selection sort, as it does not guarantee that the relative order of equal elements will be preserved.

If stability is a requirement for your sorting algorithm, you would typically opt for a stable sorting algorithm like merge sort or stable variants of quicksort or bubble sort.
