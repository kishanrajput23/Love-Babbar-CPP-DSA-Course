# Homework

**Q.1 :** How to initialize entire array with single value in c++.

**Ans :** We can use `fill_n` in C++, which assigns a value to the first `n` array elements.
```
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int arr[100];

    //To initialize the array with value '1'.
    fill_n(arr, 100, 1);

    //To check the array input
    for(int i=0; i <= 5; i++){
        cout << arr[i] << endl;
    }
}
```

**Q.2 :** Write a program using function to print the sum of an array elements.
