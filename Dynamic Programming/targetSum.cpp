#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalSum;
    int helper(vector<int>& nums, int target,int i,int sum,vector<vector<int>>& dp) {
        if(i == nums.size()){
            if(sum == target){
            return 1;
            }
            else return 0;
        }
        if(dp[i][sum + totalSum] != INT_MIN)   return dp[i][sum + totalSum];
        return dp[i][sum + totalSum] = helper(nums,target,i+1,sum+nums[i],dp) + helper(nums,target,i+1,sum-nums[i],dp);    
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(20,vector<int>(2*totalSum+1,INT_MIN));
        return helper(nums,target,0,0,dp);
    }
};