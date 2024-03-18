#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) {
            return false;
        }
        else if (front == -1) {
            rear = 0;
            front = 0;
        }
        else if (rear == size-1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.

        if (front == -1) {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == size-1) {
            front = 0;
        }
        else if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
        return ans;
    }
};