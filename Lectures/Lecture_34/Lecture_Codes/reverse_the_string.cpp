#include <bits/stdc++.h> 
void revString(string& name, int i, int j) {
    if (i>j) {
        return ;
    }

    swap(name[i], name[j]);
    i++;
    j--;

    revString(name, i, j);
}

string reverseString(string str)
{
	// Write your code here.
	revString(str, 0, str.length()-1);
	return str;
	
}