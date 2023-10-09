#include<iostream>
#include<set>
using namespace std;

int main() {
    set<int> s;

    s.insert(5);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(2);
    s.insert(2);

    cout<<"set elements are : ";
    for (auto i : s) {
        cout<<i<<" ";
    }
    cout<<endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    cout<<"after erasing, set elements are : ";
    for (auto i : s) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"3 is present in set or not : ";
    cout<<s.count(3)<<endl;

    cout<<"10 is present in set or not : ";
    cout<<s.count(10)<<endl;

    return 0;
}