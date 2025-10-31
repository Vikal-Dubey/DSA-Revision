#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pathWays(int row,int col,vector<vector<int>>& dp) {
        if(row == 0 && col == 0)    return 1;
        if(row < 0 || col < 0)   return 0;
        if(dp[row][col] != -1)  return dp[row][col];
        int rightWays = pathWays(row,col-1,dp);
        int downWays = pathWays(row-1,col,dp);
        return dp[row][col] = rightWays + downWays;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return pathWays(m-1,n-1,dp);
    }
};