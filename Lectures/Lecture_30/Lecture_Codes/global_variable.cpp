#include<iostream>
using namespace std;

//Declaring  a global variable
int a = 5;

void print()
{
    //Modifying the value of a
    a = a*5;
    //Printing the value of a
    cout<<"The value of a is "<<a<<"\n";

}
int main()
{
    //Printing the value of a
    cout<<"The value of a is "<<a<<"\n";

    //Modifying the value of a
    a = a+5;

    //Printing the value of a 
    cout<<"The value of a is "<<a<<"\n";

    //Calling the print function
    print();

    return 0;
}
