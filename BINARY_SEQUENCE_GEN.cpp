/*
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
Input: An integer n (1 <= n <= 20)
Output: Write binary sequences in a lexicographic ordder, each sequence in a line

Example
Input:
      3
Output:
      000
      001
      010
      011
      100
      101
      110
      111
*/

// Use Backtracking
#include<bits/stdc++.h>
using namespace std;

int n, a[100];
void show(){
    for(int i = 0; i<n; i++){
        cout<<a[i];
    }
    cout<<"\n";
}

void Backtracking(int k){
    for(int i = 0; i<= 1; i++){
        a[k] = i;
        if(k == n-1){
            show();
        }
        else{
            Backtracking(k+1);
        }
    }
}

int main(){
    cin >> n;
    Backtracking(0);
}
