void merge(vector < int > & arr, int start, int end) {
    int mid = start + (end - start)/2;

    int len1 = mid - start + 1;     // length of first array
    int len2 = end - mid;           // length of the second array

    int *first = new int[len1];     // dynamically creating first array
    int *second = new int[len2];    // dynamically creating second array

    // copying values in arrays
    int mainArrayIndex = start;

    for (int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for (int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // merging two arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void solve(vector < int > & arr, int start, int end) {
    if (start >= end) {
        return ;
    }

    int mid = start + (end - start)/2;

    // sorting left part of the array
    solve(arr, start, mid);

    // sorting right part of the array
    solve(arr, mid+1, end);

    // merging two sorted arrays
    merge(arr, start, end);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    solve(arr, 0, n-1);
}