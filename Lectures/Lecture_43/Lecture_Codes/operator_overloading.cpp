#include<iostream>
using namespace std;

class example {
    public:
    int a;
    int b;

    int add() {
        return a+b;
    }

    void operator+ (example obj) {
        int val1 = this->a;
        int val2 = this->b;
        int result = val2-val1;
        cout<<"result : "<<result<<endl;
    }
};

int main() {

    example obj1, obj2;
    obj1.a = 4;
    obj1.b = 10;

    cout<<obj1.add()<<endl;

    obj2.a = 10;
    obj1 + obj2;
    
    return 0;
}