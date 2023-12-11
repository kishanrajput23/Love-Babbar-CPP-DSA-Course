#include <iostream>
using namespace std;
 
// Recursive function to perform insertion sort
void insertionSort(int arr[], int n) {
    // Base case: If the array has only one element, it is already sorted
    if (n <= 1) {
        return;
    }
 
    // Sort the first n-1 elements
    insertionSort(arr, n - 1);
 
    // Insert the last element at its correct position in the sorted array
    int lastElement = arr[n - 1];
    int j = n - 2;
 
    // Shift elements greater than lastElement to the right
    while (j >= 0 && arr[j] > lastElement) {
        arr[j + 1] = arr[j];
        j--;
    }
 
    // Place lastElement at its correct position
    arr[j + 1] = lastElement;
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
 
    // Call the recursive insertion sort function
    insertionSort(arr, n);
 
    cout << "Sorted array: ";
    printArray(arr, n);
 
    return 0;
}