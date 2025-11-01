#include<bits/stdc++.h>
using namespace std;

// Top-Down
class Solution {
public:
    vector<int>dp;
    bool helper(int idx,vector<int>& nums) {
        if(idx >= nums.size()-1)  return true;
        if(dp[idx] != -1)   return dp[idx];
        if(nums[idx] >= nums.size() - 1 - idx)   return true;
        bool ans = false;
        for(int i = 1; i <= nums[idx]; i++) {
            ans = ans || helper(idx + i,nums);
            if(ans) break;
        }
        return dp[idx] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return helper(0,nums);
    }
};
//Iterative
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxReach)    return false;
            maxReach = max(maxReach,i + nums[i]);
        }
        return true;
    }
};