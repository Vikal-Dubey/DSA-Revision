#include<bits/stdc++.h>
using namespace std;
void reverseArray(vector<int> &arr , int m) {
    // Write your code here  
    int i = m+1,j = arr.size()-1;
    while(i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}