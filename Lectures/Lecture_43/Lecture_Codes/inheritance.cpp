#include<iostream>
using namespace std;

class human {
    public:
    int weight;
    int height;
    int age;

    public:
    int getAge() {
        return this->age;
    }

    void setWeight(int w) {
        this->weight = w;
    }

};

class male : public human {
    private:
    string color;

    public:
    void sleep() {
        cout<<"sleeping..."<<endl;
    }
};

int main() {

    male obj;

    obj.setWeight(100);
    cout<<obj.weight<<endl;

    obj.sleep();

    return 0;
}