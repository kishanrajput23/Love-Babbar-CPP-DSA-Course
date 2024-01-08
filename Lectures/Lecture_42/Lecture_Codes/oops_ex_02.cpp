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
    h1.setHelth(90);
    cout<<"H1 health is : "<<h1.getHealth()<<endl;
    
    h1.level = 'A';
    cout<<"H1 level is : "<<h1.level<<endl;

    // dynamically allocation
    Hero *h2 = new Hero;
    h2->setHelth(99);
    h2->setLevel('B');

    cout<<"H2 health is : "<<(*h2).getHealth()<<endl;
    cout<<"H2 level is : "<<(*h2).level<<endl;

    cout<<"H2 health is : "<<h2->getHealth()<<endl;
    cout<<"H2 level is : "<<h2->level<<endl;


    

    return 0;
}