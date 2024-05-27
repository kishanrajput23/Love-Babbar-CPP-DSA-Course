#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main() {

    // creation of map
    unordered_map<string, int> mp;

    // ways to insert value in map
    // method 1 :
    pair<string, int> p1 = make_pair("kishan", 4);
    mp.insert(p1);

    // method 2 :
    pair<string, int> p2("hello", 3);
    mp.insert(p2);

    // method 3 :
    mp["world"] = 1;

    // ways to search in map
    // method 1 :
    cout<<mp["kishan"]<<endl;

    // method 2 :
    cout<<mp.at("hello")<<endl;

    // what if we try to access a key that we didn't create or insert
    // cout<<mp.at("name")<<endl;       // this given an error as "key not found";

    // but if we try to accesss a key using below method then it return 0 because it'll first check whether 
    // that key is present or not. if it's not there then it'll make another entry and assign a value 0
    cout<<mp["name"]<<endl;

    // now if we access using below method then also we'll get same output as 0;
    cout<<mp.at("name")<<endl;

    // checking size;
    cout<<"size : "<<mp.size()<<endl;

    // checking presence
    cout<<mp.count("kishan")<<endl;     // return 1 as it is present
    cout<<mp.count("bro")<<endl;        // return 0 as it is not present

    // erasing in map
    mp.erase("name");
    cout<<"size: "<< mp.size()<<endl;

    // iterating in map
    // Method 1 : usign loop
    cout<<"iterating in map using loop: "<<endl;
    for (auto i : mp) {
        cout<<i.first<<" : "<<i.second<<endl;
    }


    // Method 2 : using iterator
    unordered_map<string, int> :: iterator it = mp.begin();
    cout<<"iterating in map using iterator: "<<endl;
    while (it != mp.end()) {
        cout<<it->first<<" : "<<it->second<<endl;
        it++;
    }

    return 0;
}