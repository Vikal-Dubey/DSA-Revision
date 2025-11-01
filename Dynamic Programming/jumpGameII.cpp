#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int idx,vector<int>& nums,vector<int>& dp) {
        if(idx >= nums.size() - 1)    return 0;
        if(dp[idx] != -1)   return dp[idx];
        int minJumps = INT_MAX;
        for(int jump = 1; jump <= nums[idx]; jump++) {
            int nextIdx = idx + jump;
            if(nextIdx < nums.size()) {
                int subResult = helper(nextIdx,nums,dp);
                if(subResult != INT_MAX) {
                    minJumps = min(minJumps,1 + subResult);
                }
            }
        }
        return dp[idx] = minJumps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(0,nums,dp);
    }
};