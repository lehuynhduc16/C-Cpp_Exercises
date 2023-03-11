// This code for fun :))
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "    C++  Programming    is    awesome    ";
    stringstream ss(s);
    string tmp;
    vector<string> v;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    for(string x:v){
        cout << x << " ";
    }
    return 0;
}

// Print  -> C++ Programming is awesome
