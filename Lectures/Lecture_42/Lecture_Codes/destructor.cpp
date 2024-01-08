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

    ~Hero() {
        cout<<"Destructor called"<<endl;
    }
};

int main() {

    // static allocation  --> for this destructor automatically called
    Hero hero1;

    // dynamic allocation  --> for this we have to call destructor explicitly
    Hero *hero2 = new Hero();
    delete hero2;

    return 0;
}