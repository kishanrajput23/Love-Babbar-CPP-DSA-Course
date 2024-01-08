#include<iostream>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char level;

    Hero() {
        cout<<"Constructor Called"<<endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHelth(int h) {
        health = h;
    }

    void setLevel(char l) {
        level = l;
    }
};

int main() {

    // static allocation
    Hero h1;

    // dynamically allocation
    Hero *h2 = new Hero;


    

    return 0;
}