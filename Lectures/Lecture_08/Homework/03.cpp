#include <iostream>

using namespace std;

int main()
{
    int amount;
    cout<<"Enter the total amount : ";
    cin>>amount;
    
    int rs100, rs50, rs20, rs1;
    
    cout<<"The total number of notes required : "<<endl;
    
    switch(1) {
        case 1 :
        rs100 = amount / 100;
        amount %= 100;
        cout<<"Rs 100 : "<<rs100<<endl;
        
        case 2 :
        rs50 = amount / 50;
        amount %= 50;
        cout<<"Rs 50 : "<<rs50<<endl;
        
        case 3 :
        rs20 = amount / 20;
        amount %= 20;
        cout<<"Rs 20 : "<<rs20<<endl;
        
        case 4 :
        rs1 = amount / 1;
        amount %= 1;
        cout<<"Rs 1 : "<<rs1<<endl;
    }

    return 0;
}
