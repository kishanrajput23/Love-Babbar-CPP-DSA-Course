#include<iostream>
using namespace std;

class Human {
    public:
    void speak() {
        cout<<"speaking.."<<endl;
    }
};

class Male : public Human {
    public:
    void speak() {
        cout<<"yelling..."<<endl;
    }

};

int main() {
    Male m;
    m.speak();

    return 0;
}