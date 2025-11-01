#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int idx,vector<int>& coins, int amount) {
        if(idx >= coins.size()) {
            return INT_MAX-100;
        }
        if(amount < 0) {
            return INT_MAX-100;
        }
        if(amount == 0) {
            return 0;
        }
        if(dp[idx][amount] != -1)   return dp[idx][amount];
        int take = 1 + solve(idx,coins,amount-coins[idx]);
        int skip = solve(idx+1,coins,amount);
        return dp[idx][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        if(amount == 0) return 0;
        int ans = solve(0,coins,amount);
        return ans == INT_MAX-100 ? -1 : ans;
    }
};