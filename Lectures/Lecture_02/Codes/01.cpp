#include <iostream>

using namespace std;

int main()
{
    int num = 123;
    cout<<num<<endl;
    cout<<"Size of integer is "<<sizeof(num)<<" bytes\n"<<endl;
    
    char ch = 'k';
    cout<<ch<<endl;
    cout<<"Size of character is "<<sizeof(ch)<<" bytes\n"<<endl;
    
    bool bl = true;
    cout<<bl<<endl;
    cout<<"Size of bool is "<<sizeof(bl)<<" bytes\n"<<endl;
    
    float f = 1.2;
    cout<<f<<endl;
    cout<<"Size of float is "<<sizeof(f)<<" bytes\n"<<endl;
    
    double d = 32.678;
    cout<<d<<endl;
    cout<<"Size of double is "<<sizeof(d)<<" bytes\n"<<endl;
    
    int a = 'a';
    cout<<"The value of a is "<<a<<endl;
    
    char b = 98;
    cout<<"The value of b is "<<b<<endl;
    
    int num1 = 20;
    int num2 = 40;
    
    cout<<(num1==num2)<<endl;
    cout<<(num1>num2)<<endl;
    cout<<(num1<num2)<<endl;
    cout<<(num1!=num2)<<endl;

    return 0;
}
