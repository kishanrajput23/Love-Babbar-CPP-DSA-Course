#include<iostream>
using namespace std;

class kqueue {
    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    kqueue(int n, int k) {
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];

        for (int i=0; i<k; i++) {
            front[i]  = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i=0; i<n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];
        freespot = 0;
    }

    void enqueue(int data, int qn) {
        // overflow
        if (freespot == -1) {
            cout<<"No empty space."<<endl;
            return;
        }

        // finding index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // check whether it is first element to insert
        if (front[qn-1] == -1) {
            front[qn-1] = index;
        }
        else {
            // link new element with the previous element
            next[rear[qn-1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn-1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn) {
        // check underflow
        if (front[qn-1] == -1) {
            cout<<"queue is underflow"<<endl;
            return -1;
        }

        // find index to pop
        int index = front[qn-1];

        // move front ahead
        front[qn-1] = next[index];

        // manage free spot
        next[index] = freespot;
        freespot = index;

        return arr[index];
    } 

};

int main() {

    kqueue q(10, 3);

    q.enqueue(5, 1);
    q.enqueue(10, 1);
    q.enqueue(20, 2);
    q.enqueue(15, 1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    
    return 0;
}