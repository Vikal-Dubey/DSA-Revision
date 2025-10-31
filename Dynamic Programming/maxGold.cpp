#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>>dir = {{-1,1},{0,1},{1,1}};
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& mat,int row,int col) {
        int m = mat.size();
        int n = mat[0].size();
        if(row == m && col == n) {
            return 0;
        }
        if(row < 0 || row >= m || col < 0 || col >= n) {
            return 0;
        }
        if(dp[row][col] != -1)  return dp[row][col];
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            int newR = row + dir[i][0];
            int newC = col + dir[i][1];
            ans = max(ans,mat[row][col] + solve(mat,newR,newC));
        }
        return dp[row][col] = ans;
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        dp.resize(n,vector<int>(m,-1));
        for(int i = 0; i < n; i++) {
            ans = max(ans,solve(mat,i,0));
        }
        return ans;
    }
};