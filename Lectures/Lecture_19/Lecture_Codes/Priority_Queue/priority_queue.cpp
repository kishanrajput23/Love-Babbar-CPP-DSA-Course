#include<iostream>
#include<queue>
using namespace std;

int main() {

    priority_queue<int> maxi;    // by default it create max heap

    priority_queue<int, vector<int>, greater<int> > mini;    // this will create a min heap
    
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(4);
    maxi.push(0);
    cout<<"size of priority queue (maxi) is : "<<maxi.size()<<endl;

    int n1 = maxi.size();
    for (int i=0; i<n1; i++) {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(4);
    mini.push(0);
    cout<<"size of priority queue (mini) is : "<<mini.size()<<endl;

    int n2 = mini.size();
    for (int i=0; i<n2; i++) {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;

    return 0;
}