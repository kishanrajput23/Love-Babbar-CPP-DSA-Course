#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	// Write your code here.
	string temp = "";
    for (int i=0; i<str.length(); i++) {
        if (str[i] == ' ') {
            temp += "@40";
        }
        else {
            temp += str[i];
        }
    }
    return temp;
}


//  another version of solving same problem without creating another empty string
// #include <iostream>
// #include <string>

// void replaceSpacesInPlace(std::string &str) {
//     for (int i = 0; i < str.length(); i++) {
//         if (str[i] == ' ') {
//             str.replace(i, 1, "@40");
//             i += 3; // Move the index forward to skip the added characters
//         }
//     }
// }

// int main() {
//     std::string str = "Hello Ji Kese Ho Sare";
//     replaceSpacesInPlace(str);
//     std::cout << str << std::endl;
//     return 0;
// }
