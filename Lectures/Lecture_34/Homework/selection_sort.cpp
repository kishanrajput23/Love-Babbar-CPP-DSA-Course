#include <iostream>
using namespace std;
 
// Function to find the minimum element in the array
int findMinIndex(int arr[], int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
 
// Recursive function to perform selection sort
void selectionSort(int arr[], int start, int end) {
    if (start < end) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = findMinIndex(arr, start, end);
 
        // Swap the found minimum element with the first element
        swap(arr[start], arr[minIndex]);
 
        // Recursively sort the rest of the array
        selectionSort(arr, start + 1, end);
    }
}
 
// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Original array: ";
    printArray(arr, n);
 
    // Call the recursive selection sort function
    selectionSort(arr, 0, n - 1);
 
    cout << "Sorted array: ";
    printArray(arr, n);
 
    return 0;
}