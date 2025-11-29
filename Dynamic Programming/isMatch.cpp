#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string s,int i,string p,int j,int& n,int &m,vector<vector<int>>& dp) {
        if(i >= n && j >= m) {
            return true;
        } else if(j >= m) {
            return false;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        bool match = (i < n && (s[i] == p[j] || p[j] == '.'));

        if(j+1 < m && p[j+1] == '*') {
            return dp[i][j] = solve(s,i,p,j+2,n,m,dp) || (match && solve(s,i+1,p,j,n,m,dp));
        } else {
            return dp[i][j] = (match && solve(s,i+1,p,j+1,n,m,dp));
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,0,p,0,n,m,dp);
    }
};