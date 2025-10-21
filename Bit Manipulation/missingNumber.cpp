#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xOr = n;
        for(int i = 0; i < n; i++) {
            xOr ^= i ^ nums[i];
        }
        return xOr;
    }
};