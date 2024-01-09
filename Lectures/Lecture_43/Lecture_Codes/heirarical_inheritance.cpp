#include<iostream>
using namespace std;

class Animal {
    
    public:
    int age;

    void speak() {
        cout<<"speaking..."<<endl;
    }
};

class Dog : public Animal {

    public:
    int age;

    void bark() {
        cout<<"barking..."<<endl;
    }
};

class Cat : public Animal {

    public:
    int age;

    void meow() {
        cout<<"meow..."<<endl;
    }
};

int main() {

    Dog d;
    d.speak();
    d.bark();

    Cat c;
    c.speak();
    c.meow();

    return 0;
}