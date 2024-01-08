#include<iostream>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char level;

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
    Hero *h = new Hero;

    // using getter
    cout<<"H1 health is : "<<h1.getHealth()<<endl;

    // using setter
    h1.setHelth(90);
    cout<<"H1 health is : "<<h1.getHealth()<<endl;

    h1.level = 'A';
    cout<<"H1 level is : "<<h1.level<<endl;

    return 0;
}