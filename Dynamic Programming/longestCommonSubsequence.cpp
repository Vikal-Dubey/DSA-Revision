#include<bits/stdc++.h>
using namespace std;
// Top Down
class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &text1, string &text2,int i,int j) {
        if(i >= text1.size() || j >= text2.size())  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(text1[i] == text2[j])    return dp[i][j] = 1 + solve(text1,text2,i+1,j+1);
        else {
            return dp[i][j] = max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(text1,text2,0,0);
    }
};
//Bottom up
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int row = 0; row < m+1; row++) {
            dp[row][0] = 0;
        }
        for(int col = 0; col < n+1; col++) {
            dp[0][col] = 0;
        }
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};