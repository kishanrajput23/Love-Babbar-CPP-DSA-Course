#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);

    cout<<"finding 6 --> "<<binary_search(v.begin(), v.end(), 6)<<endl;
    cout<<"finding 1 --> "<<binary_search(v.begin(), v.end(), 1)<<endl;

    cout<<"lower bound : "<<lower_bound(v.begin(), v.end(), 3) - v.begin()<<endl; 

    cout<<"upper bound : "<<upper_bound(v.begin(), v.end(), 3) - v.begin()<<endl; 

    int a = 30;
    int b = 50;

    cout<<"maxi : "<<max(a, b)<<endl;
    cout<<"mini : "<<min(a, b)<<endl;

    cout<<"before swapping --> ";
    cout<<"a : "<<a<<" b : "<<b<<endl;

    swap(a, b);

    cout<<"after swapping --> ";
    cout<<"a : "<<a<<" b : "<<b<<endl;

    string s = "abcdefgh";
    cout<<"before reverse string s : ";
    cout<<s<<endl;
    reverse(s.begin(), s.end());

    cout<<"after reverse string s : ";
    cout<<s<<endl;

    cout<<"before rotate vector v elements are : ";
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    rotate(v.begin(), v.begin()+1, v.end());

    cout<<"after rotate vector v elements are : ";
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}