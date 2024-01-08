#include<iostream>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char* name;
    char level;

    // Default Constructor  ||    Shallow Copy
    Hero() {
        name = new char[100];
        cout<<"Constructor Called"<<endl;
    }


    // Parametrised constructor
    Hero(int health) {
        this->health = health;
    }

    Hero(int health, char level) {
        this->level = level;
        this->health = health;
    }

    // Copy constructor    ||    Deep Copy
    Hero(Hero& temp) {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout<<"Copy constructor called"<<endl;
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

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    void print() {
        cout<<"name : "<<this->name<<endl;
        cout<<"level : "<<this->level<<endl;
        cout<<"health : "<<this->health<<endl<<endl;
    }
};

int main() {

    Hero hero1;

    hero1.setHelth(90);
    hero1.setLevel('A');
    char name[7] = "Kishan";
    hero1.setName(name);
    hero1.print();

    // default copy constructor uses shallow copy
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'B';
    hero1.print();

    hero2.print();

    hero1 = hero2;      // copy assignment operator
    hero1.print();

    return 0;
}