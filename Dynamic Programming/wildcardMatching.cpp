#include<bits/stdc++.h>
using namespace std;

// Memoization Method
class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string &s,int i,string &p,int j) {
        if(i == 0 && j == 0) {
            return true;
        } else if(i == 0 && j > 0) {
            return false;
        } else if(i > 0 && j == 0) {
            while(i > 0) {
                if(s[i-1] != '*') return false;
                i--;
            }
            return true;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i-1] == p[j-1] || s[i-1] == '?') {
            return dp[i][j] = solve(s,i-1,p,j-1);
        }
        if(s[i-1] == '*') {
            return dp[i][j] = solve(s,i-1,p,j) || solve(s,i,p,j-1);
        }
        return false;
    }
    bool isMatch(string p, string s) {
        int n = s.size(),m = p.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(s,s.size(),p,p.size());
    }
};


// Tabulation Method
class Solution {
public:
    bool isMatch(string p, string s) {
        int n = s.size(),m = p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }
        for(int i = 1; i <= n; i++) {
            bool flag = true;
            for(int ii = 1; ii <= i; ii++) {
                if(s[ii-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == p[j-1] || s[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(s[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};