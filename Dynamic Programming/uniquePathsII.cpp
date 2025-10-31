#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> obstacleGrid,dp;
    int n,m;
    int path(int i,int j){
        if(dp[i][j] != -1)  return dp[i][j];
        if(i == n-1 && j == m-1)    return dp[i][j] = 1;
        if(i >= n || j >= m)    return dp[i][j] = 0;
        if(obstacleGrid[i][j] == 1) return dp[i][j] = 0;
        return dp[i][j] = path(i+1,j) + path(i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid ) {
        // obstacleGrid = grid;
        dp.clear();
        dp.resize(105,vector<long long>(105,0));
        n = grid.size();
        m = grid[0].size();
        if(grid[n-1][m-1] == 1) return 0;
        dp[n-1][m-1] = 1;
        for(int i = n-2;i>=0;i--){
            if(grid[i][m-1] == 1)   dp[i][m-1] = 0;
            else dp[i][m-1] = dp[i+1][m-1];
        }
        for(int i = m-2;i>=0;i--){
            if(grid[n-1][i] == 1)   dp[n-1][i] = 0;
            else dp[n-1][i] = dp[n-1][i+1];
        }
        for(int i = n-2;i>=0;i--){
            for(int j = m-2;j>=0;j--){
                if(grid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};