#include <bits/stdc++.h> 

int firstOccurrence(vector<int>& arr, int size, int key) {

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    int ans = -1;

    while (start <= end) {

        if (arr[mid] == key) {
            ans = mid;
            end = mid-1;
        }

        //go to right wala part
        else if (key > arr[mid]) {
            start = mid + 1;
        }
        
        //key < arr[mid] go to left wala part
        else if (key < arr[mid]) { 
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return ans;
}
int lastOccurrence(vector<int>& arr, int size, int key) {

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    int ans = -1;

    while (start <= end) {

        if (arr[mid] == key) {
            ans = mid;
            start = mid+1;
        }

        //go to right wala part
        else if (key > arr[mid]) {
            start = mid + 1;
        }
        
        //key < arr[mid] go to left wala part
        else if (key < arr[mid]) { 
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int, int> p;
    p.first = firstOccurrence(arr, n, k);
    p.second = lastOccurrence(arr, n, k);
    return p;
}