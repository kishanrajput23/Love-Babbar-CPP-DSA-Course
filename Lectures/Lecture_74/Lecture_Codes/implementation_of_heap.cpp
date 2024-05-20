#include<iostream>
#include<queue>

using namespace std;

/*
Left node : 2*i where i is index
right node : 2*i+1
root node : i/2;
left node : n/2 + 1 to nth node
*/

class heap {
    public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index  > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
            }
            else {
                return ;
            }

        }
    }

    void deleteFromHeap() {
        if (size == 0) {
            cout<<"Nothing to delete"<<endl;
        }

        // step 1 : put last element to first index;
        arr[1] = arr[size];

        // step 2 : remove last element
        size--;

        // step 3 : take root node to its correct position
        int index = 1;
        while (index < size) {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            if (leftIndex < size && arr[leftIndex] > arr[index]) {
                swap(arr[leftIndex], arr[index]);
                index = leftIndex;
            }
            else if (rightIndex < size && arr[rightIndex] > arr[index]) {
                swap(arr[rightIndex], arr[index]);
                index = rightIndex;
            }
            else {
                return ;
            }
        }
    }

    void print() {
        for (int i=1; i<=size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

// hapify algo [T.C = log(n)]
// building max heap [1 based indexing]
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// heap sorting
void heapSort(int arr[], int n) {
    int size = n;

    while (size > 1) {
        // step 1 : swap
        swap(arr[size], arr[1]);
        size--;

        // step 2 : heapify
        heapify(arr, size, 1);
    }
}

int main() {

    heap hp;

    // insertion in heap
    hp.insert(50);
    hp.insert(55);
    hp.insert(53);
    hp.insert(52);
    hp.insert(54);
    hp.print();

    // deletion in heap
    hp.deleteFromHeap();
    hp.print();

    // heapify algo or heap creation
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i=n/2; i>0; i--) {     // doing n/2 beacuse we don't have to do process for leaf nodes
        heapify(arr, n, i);
    }

    cout<<"Printing Max Heap : ";
    for (int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // heap sort
    heapSort(arr, n);
    cout<<"Printing After Heap Sort : ";
    for (int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // max heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(2);
    pq.push(5);
    pq.push(20);
    pq.push(12);
    cout<<"Top element : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Size of pq : "<<pq.size()<<endl;

    // min heap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(10);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(12);
    cout<<"Top element : "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Size of pq : "<<minHeap.size()<<endl;

    return 0;
}