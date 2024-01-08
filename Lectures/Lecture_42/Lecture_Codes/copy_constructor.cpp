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


     // parametrised constructor
    Hero(int health) {
        this->health = health;
    }

    Hero(int health, char level) {
        this->level = level;
        this->health = health;
    }

    // copy constructor
    Hero(Hero& temp) {
        this->health = temp.health;
        this->level = temp.level;
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

    void print() {
        cout<<"level : "<<level<<endl;
        cout<<"health : "<<health<<endl;
    }
};

int main() {

    // static allocation
    Hero H1(10, 'A');
    H1.print();


    Hero H2(H1);
    H2.print();

    return 0;
}