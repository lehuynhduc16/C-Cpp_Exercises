/*
Tìm tập các khoảng thời gian không giao nhau lớn nhất
      • Cho đầu vào là tập X gồm n khoảng thời gian X = {(a1, b1), . . . , (an, bn)} với ai < bi
      • Hãy tìm và đưa ra tập con lớn nhất của X chứa các khoảng thời gian này sao cho không có 2 khoảng nào giao nhau
Input
      • Dòng 1 là giá trị của n (1 <= n <= 100000)
      • Các dòng tiếp theo là các khoảng thời gian (ai, bi) (1 <= ai <= bi <= 1000000)
Output
      • Số lượng phần tử của tập con lớn nhất

Sample Test
Input:
      6
      0 10
      3 7
      6 14
      9 11
      12 15
      17 19
Output:
      4
*/

#include <bits/stdc++.h>
using namespace std;

int end_prioritize(int n, pair <int, int> arr[]){
    sort(arr, arr + n);
    int mem = arr[0].first, count = 1;
    for(int i = 1; i < n; i++){
        if(arr[i].second > mem){
            count += 1;
            mem = arr[i].first;
        }
    }
    return count;
}

int start_prioritize(int n, pair <int, int> brr[]){
    sort(brr, brr + n);
    int mem = brr[0].second, count = 1;
    for(int i = 1; i < n; i++){
        if(brr[i].first >= mem){
            count += 1;
            mem = brr[i].second;
        }
    }
    return count;
}

//  distance_prioritize()

int main(){
    int n;
    cin >> n;
    pair<int, int> arr[n];
    pair<int, int> brr[n];
    for(int i = 0; i < n; i++){

        cin >> arr[i].second >> arr[i].first;
        brr[i].first = arr[i].second;
        brr[i].second = arr[i].first;
    }
    int e = end_prioritize(n, arr);
    int s = start_prioritize(n, brr);
    cout << max(e, s) << endl;
    return 0;
}
