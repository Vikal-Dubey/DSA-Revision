#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int idx,vector<int>& coins, int amount) {
        if(idx >= coins.size()) {
            return 0;
        }
        if(amount < 0) {
            return 0;
        }
        if(amount == 0) {
            return 01;
        }
        if(dp[idx][amount] != -1)   return dp[idx][amount];
        int take = solve(idx,coins,amount-coins[idx]);
        int skip = solve(idx+1,coins,amount);
        return dp[idx][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return solve(0,coins,amount);
    }
};