#include<iostream>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char* name;
    char level;
    static int x;

    // Default Constructor 
    Hero() {
        cout<<"Constructor Called"<<endl;
    }

    static int random(){
        cout<<"random"<<endl;
        return x;
    }

    ~Hero() {
        cout<<"Destructor called"<<endl;
    }
};

int Hero :: x = 5;      // ways to declare static variable outside the class

int main() {

    cout<<"value of static x : "<<Hero::x<<endl;

    Hero h;
    cout<<h.x<<endl;
    h.random();

    return 0;
}