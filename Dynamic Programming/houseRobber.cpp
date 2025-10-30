#include<bits/stdc++.h>
using namespace std;
// Recursive method
class Solution {
public:
    int helper(vector<int>& arr,int i,vector<int>& dp){
        if(i == arr.size()-1)   return arr[i];
        if(i == arr.size()-2)   return max(arr[i],arr[i+1]);
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(arr[i] + helper(arr,i+2,dp),helper(arr,i+1,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,0,dp);   
    }
};
// Tabulation method
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        if(n == 2)  return max(nums[0],nums[1]);
        vector<int>dp(n);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i = n-3;i>=0;i--){
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};