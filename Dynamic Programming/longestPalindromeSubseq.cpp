#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSub(int i,int j,string &s,vector<vector<int>>& dp) {
        if(i > j)   return 0;
        if(i == j)  return 1;
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == s[j]) {
            dp[i][j] = 2 + findSub(i+1,j-1,s,dp);
        } else {
            dp[i][j] = max(findSub(i+1,j,s,dp),findSub(i,j-1,s,dp));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findSub(0,s.size()-1,s,dp);
    }
};