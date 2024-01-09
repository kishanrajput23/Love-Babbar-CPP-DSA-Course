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

class Puppy : public Dog {

};

int main() {

    Puppy obj;

    obj.speak();
    obj.bark();

    return 0;
}