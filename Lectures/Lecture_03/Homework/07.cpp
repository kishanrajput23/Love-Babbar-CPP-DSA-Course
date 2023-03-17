#include <iostream>

using namespace std;

int main()
{
    int f;
    cout<<"Enter the temprature in fahrenheit (F) : ";
    cin>>f;
    
    float c = (f-32) * (5.0/9);
    
    cout<<"The temprature in celcius (C) : "<<c<<endl;
    
    return 0;
}
