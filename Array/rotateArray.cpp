#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseArray(vector<int> &arr , int start,int end) { 
        int i = start,j = end;
        while(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverseArray(nums,0,n-k-1);
        reverseArray(nums,n-k,n-1);   
        reverseArray(nums,0,n-1);  
    }
};