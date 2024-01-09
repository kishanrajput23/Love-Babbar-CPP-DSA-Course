#include<iostream>
using namespace std;

class Animal {
    
    public:
    int age;

    void speak() {
        cout<<"speaking..."<<endl;
    }
};

class Dog {

    public:
    int age;

    void bark() {
        cout<<"barking..."<<endl;
    }
};

class Puppy : public Animal, public Dog {

};

int main() {

    Puppy obj;

    obj.speak();
    obj.bark();

    return 0;
}