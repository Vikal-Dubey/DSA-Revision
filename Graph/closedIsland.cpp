#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                q.push({i,0});
                grid[i][0] = 1;
            }
            if(grid[i][m-1] == 0) {
                q.push({i,m-1});
                grid[i][m-1] = 1;
            }
        }
        for(int j = 1; j < m-1; j++) {
            if(grid[0][j] == 0) {
                q.push({0,j});
                grid[0][j] = 1;
            }
            if(grid[n-1][j] == 0) {
                q.push({n-1,j});
                grid[n-1][j] = 1;
            }
        }
        vector<vector<int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == 1) {
                    continue;
                }
                grid[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                    q.push({i,j});
                    grid[i][j] = 1;
                    while(!q.empty()) {
                        auto [r,c] = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++) {
                            int nr = r + dir[i][0];
                            int nc = c + dir[i][1];
                            if(nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == 1) {
                                continue;
                            }
                            grid[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return ans;
    }
};