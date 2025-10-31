#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int solve(vector<vector<int>>& grid,int i,int j) {
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }
        int gold = grid[i][j];
        grid[i][j] = 0;
        int ans = 0;
        for(int d = 0; d < 4; d++) {
            int newR = i + dir[d][0];
            int newC = j + dir[d][1];
            ans = max(ans,gold + solve(grid,newR,newC));
        }
        grid[i][j] = gold;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                ans = max(ans,solve(grid,i,j));
            }
        }
        return ans;
    }
};