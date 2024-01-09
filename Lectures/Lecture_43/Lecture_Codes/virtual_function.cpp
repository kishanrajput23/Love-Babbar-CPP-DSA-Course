#include <iostream>
using namespace std;
class A {
public:
    virtual void display() {
        cout << "Base class is invoked" << endl;
    }
};

class B : public A {
public:
    void display() {
        cout << "Derived Class is invoked" << endl;
    }
};
int main()
{
    A *a; // pointer of base class
    B b;  // object of derived class
    a = &b;
    a->display(); // Late Binding occurs
    return 0;
}