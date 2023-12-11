#include <bits/stdc++.h> 

int firstIndex(vector<int>& arr, int currIndex, int size, int key){
    if (size == currIndex){
        return -1;
    }

    if(arr[currIndex] == key){
        return currIndex;
    }
    
    return firstIndex(arr, currIndex+1, size, key);
}


int lastIndex(vector<int>& arr, int currIndex, int size, int key) {
    if (currIndex== size){
        return -1;
    }
    
    int index = lastIndex(arr, currIndex+1, size, key);

    if (index == -1 && arr[currIndex] == key) {
        return currIndex;
    }
    else {
        return index;
    }
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int, int> p;
    p.first = firstIndex(arr,0, n, k);
    p.second = lastIndex(arr, 0, n, k);
    return p;
}