#include <bits/stdc++.h> 

int partition(vector<int>& arr, int start, int end) {

    int pivot = arr[start];

    int count = 0;

    // calculating the mnumber of value which are less then pivot
    for (int i=start+1; i<=end; i++) {
        if (arr[i]<=pivot) {
            count++;
        }
    }

    // plcing pivot at right position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i=start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        } 
    }

    return pivotIndex;

}

void solve(vector<int>& arr, int start, int end) {

    if (start  >= end) {
        return ;
    }

    int p = partition(arr, start, end);

    // sorting the left part of the array
    solve(arr, start, p-1);

    // sorting the right part of the array
    solve(arr, p+1, end);
}


vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    solve(arr, 0, arr.size()-1);
    return arr;
}
