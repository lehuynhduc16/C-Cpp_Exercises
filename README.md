# Learn-Cpp

This is where my Cplusplus exercises and notes are stored


// Standard Template Library (STL) in C++ 

#include <bits/stdc++.h>

using namespace std;


bool cmp(int a, int b){  //state_sort

    return abs(a) < abs(b);
}

int main(){

    //// max, min
    int a[6] = {1, 6, 9, 11, -4, 17};
    vector<int> v = {4, 7, -10, 11};
    cout << "Max = " << max(1, 6) << endl;
    cout << "Min = " << min({1, 2, 3, 4}) << endl;


    //// min_element, max_element
    // -> Compare mang, vector
	cout << "Max = " << *max_element(a, a+6) << endl;
    cout << "Min = " << *min_element(begin(v), end(v)) << endl;
    

    //// accumulate
    // -> Sum of array, vector
    cout << "Sum arr = " << accumulate(a, a+4, 0) << endl;
    //-> = Sum from a[0] to a[3] add with [0]
    cout << "Sum vtr = " << accumulate(begin(v), begin(v)+2, 10) << endl;
    //-> = Sum from v[0] to a[1] add with [10]
	

    //// sort

    // Sort array
    int b[5] = {1, 5, 9, -10, 6};
    sort(b, b+5);
    cout << "Mang b sau khi sap xep tang dan: ";            // Sort up ascending
    for(int x:b){
        cout << x << ", ";
    }
    cout << endl;

    // Sort vector
    vector<int> c = {12, 7, -5, 4, -9};
    sort(begin(c), end(c), greater<int>());
    cout << "Vector c sau khi sap xep giam dan: ";          // Sort descending
    for(int x:c){
        cout << x << ", ";
    }
    cout << endl;

    // Sort string
    string str[5] = {"python", "java", "c", "c++", "sql"};
    cout << "String str sau khi sap xep: ";                 // Sort string
    sort(str, str+5);
    for(string x:str){
        cout << x << ", ";
    }
    cout << endl;

    //// stable_sort - Sap xep theo |x| tang dan
    int d[8] = {-4, -1, 3, 4, -1, 2, 10, -2};
    cout << "Mang d sau khi sap xep: ";                     // Sort by ascending |x|
    stable_sort(a, a+8, cmp);
    for(int x:d){
        cout << x << ", ";
    }
    cout << endl;

    //// find
    // array
    int e[5] = {4, 7, -19, 36, 2};
    auto it = find(e, e+5, 3);
    if(it == e+5){
        cout << "FIND: NOT FOUND";
    }
    else{
        cout << "FIND: FOUND";
    }
    cout << endl;

    // vector
    vector<int> f = {4, 7, -19, 36, 2};
    auto it1 = find(f.begin(), f.end(), -19);
    if(it1 == f.end()){
        cout << "FIND: NOT FOUND" << endl;
    }
    else{
        cout << "FIND: FOUND";
    }
    cout << endl;

    //// binary_search
    int g[6] = {1, 2, 3, 4, 5, 6};
    if(binary_search(g, g+5, 2)){
        cout << "BINARY SEARCH: NOT FOUND";
    }
    else{
        cout << "BINARY SEARCH: FOUND";
    }
    cout << endl;


    //// memset
    // -> Bien cac phan tu cua mang thanh 0
    int h[5] = {4, 8, 10, -6, 6};
    cout << "Bien thanh 0: ";
    memset(h, 0, sizeof(h));
    for(int x:h){
        cout << x << ", ";
    }

    // Hoac bien thanh -1
    cout << endl << "Bien thanh -1: ";
    memset(h, -1, sizeof(h));
    for(int x:h){
        cout << x << ", ";
    }
    cout << endl;


    //// fill
    vector<int> k(10);
    fill(k.begin(), k.end(), 100);
    cout << "Mang k: ";
    for(int x:k){
        cout << x << ", ";
    }
    cout << endl;

    //// merge (Trộn)
    vector<int> m = {1, 2, 3, 3, 4};
    vector<int> n = {1, 1, 2, 5, 16};
    vector<int> res(13);
    merge(m.begin(), m.end(), n.begin(), n.end(), res.begin());
    cout << "Merge (TRỘN): ";
    for(int x:res){
        cout << x << ", ";
    }
    cout << endl;

    //// Reverse
    // integer
    int p[] = {1, 3, 5, 7, 9};
    reverse(p, p+5);
    cout <<"Reverse integer: ";
    for(int x:p){
        cout << x << ", ";
    }
    cout << endl;

    // string
    string s = "Manchester City";
    cout <<"Reverse string: ";
    reverse(begin(s), end(s));
    cout << s << endl;



    int q[] = {1, 2, 3, 4, 5, 8};
    int r[] = {1, 3, 4, 5, 6, 11};
    cout << "q[] = {1, 2, 3, 4, 5, 8}" << endl;
    cout << "r[] = {1, 3, 4, 5, 6, 11}" << endl;
    //// set_union
    // -> HỢP của 2 mảng, cần được sắp xếp trước
    vector<int> u1(12);
    auto it2 = set_union(q, q+6, r, r+6, u1.begin());
    u1.resize(it2 - u1.begin());
    cout << "set_union(HỢP): ";
    for(int x:u1){
        cout << x << ", ";
    }
    cout << endl;


    //// set_intersection
    // -> GIAO của 2 mảng, cần được sắp xếp trước
    vector<int> u2(12);
    auto it3 = set_intersection(q, q+6, r, r+6, u2.begin());
    u2.resize(it3 - u2.begin());
    cout << "set_intersection (GIAO): ";
    for(int x:u2){
        cout << x << ", ";
    }
    cout << endl;


    //// set_difference
    // -> Thuộc q nhưng không thuộc r
    vector<int> u3(12);
    auto it4 = set_difference(q, q+6, r, r+6, u3.begin());
    u3.resize(it4 - u3.begin());
    cout << "set_difference: ";
    for(int x:u3){
        cout << x << ", ";
    }
    cout << endl;


    //// set_symmetric_difference
    // -> Hợp - Giao
    vector<int> u4(12);
    auto it5 = set_symmetric_difference(q, q+6, r, r+6, u4.begin());
    u4.resize(it5 - u4.begin());
    cout << "set_symmetric_difference (Hợp - Giao): ";
    for(int x:u4){
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}

	_____________________________ RUN _____________________________
Max = 6

Min = 1

Max = 17

Min = -10

Sum arr = 27

Sum vtr = 21

Mang b sau khi sap xep tang dan: -10, 1, 5, 6, 9, 

Vector c sau khi sap xep giam dan: 12, 7, 4, -5, -9, 

String str sau khi sap xep: c, c++, java, python, sql, 

Mang d sau khi sap xep: -4, -1, 3, 4, -1, 2, 10, -2, 

FIND: NOT FOUND

FIND: FOUND

BINARY SEARCH: NOT FOUND

Biến thành 0: 0, 0, 0, 0, 0, 

Biến thành -1: -1, -1, -1, -1, -1, 

Mang k: 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 

Merge (TRỘN): 1, 1, 1, 2, 2, 3, 3, 4, 5, 16, 0, 0, 0, 

Reverse integer: 9, 7, 5, 3, 1, 

Reverse string: ytiC retsehcnaM

q[] = {1, 2, 3, 4, 5, 8}

r[] = {1, 3, 4, 5, 6, 11}

set_union(HỢP): 1, 2, 3, 4, 5, 6, 8, 11, 

set_intersection (GIAO): 1, 3, 4, 5, 

set_difference: 2, 8, 

set_symmetric_difference (Hợp - Giao): 2, 6, 8, 11, 
