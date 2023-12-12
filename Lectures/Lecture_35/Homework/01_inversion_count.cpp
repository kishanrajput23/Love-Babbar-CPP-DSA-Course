// brute force approach
// Time Complexity: O(N2), Two nested loops are needed to traverse the array from start to end.
// Auxiliary Space: O(1), No extra space is required.

#include <iostream>
using namespace std;
 
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
 
    return inv_count;
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are "<< getInvCount(arr, n) << endl;
    return 0;
}