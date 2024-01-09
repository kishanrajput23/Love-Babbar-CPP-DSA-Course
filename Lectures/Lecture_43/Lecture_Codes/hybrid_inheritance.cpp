#include<iostream>
using namespace std;

class A {
    public:
    void func1() {
        cout<<"func 1"<<endl;
    }
};

class D {
    public:
    void func4() {
        cout<<"func 4"<<endl;
    }
};

class B : public A {
    public:
    void func2() {
        cout<<"func 2"<<endl;
    }
};

class C : public A, public D {
    public:
    void func3() {
        cout<<"func 3"<<endl;
    }
};

int main() {
    A a;
    cout<<"object a call : "<<endl;
    a.func1();


    B b;
    cout<<"object b call : "<<endl;
    b.func1();
    b.func2();

    C c;
    cout<<"object c call : "<<endl;
    c.func1();
    c.func3();
    c.func4();

    D d;
    cout<<"object d call : "<<endl;
    d.func4();

    return 0;
}