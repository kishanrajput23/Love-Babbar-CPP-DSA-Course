#include <bits/stdc++.h> 

// hapify algo [T.C = log(n)]
void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }

    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for (int i=n/2-1; i>=0; i--) {     // doing n/2 beacuse we don't have to do process for leaf nodes
        heapify(arr, n, i);
    }
    return arr;
}
