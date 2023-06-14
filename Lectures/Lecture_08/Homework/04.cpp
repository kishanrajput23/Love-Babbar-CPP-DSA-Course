#include <iostream>

using namespace std;

int findNthTerm(int n) {
    int ans = 3 * n + 7;
    return ans;
}

int main()
{
    int n;
    cout<<"Given AP : 3*n+7"<<endl;
    cout<<"Enter the value of n to find nth term : ";
    cin>>n;
    
    cout<<"The nth term value is : "<<findNthTerm(n)<<endl;
    return 0;
}
