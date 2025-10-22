#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>>block;
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{1,0},{0,1}};
    bool solve(int maxArea,vector<int>& source, vector<int>& target) {
        set<pair<int,int>>vis;
        queue<pair<int,int>>que;
        que.push({source[0],source[1]});
        int cnt = 0;
        while(!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            if(row == target[0] && col == target[1])    return true;
            if(cnt > maxArea)   return true;
            for(int i = 0; i < 4; i++) {
                int newRow = row + adj[i].first;
                int newCol = col + adj[i].second;
                if(newRow >= 0 && newCol >= 0 && newRow < 1e6 && newCol < 1e6) {
                    if(!vis.count({newRow,newCol}) && !block.count({newRow,newCol})) {
                        que.push({newRow,newCol});
                        vis.insert({newRow,newCol});
                    }
                }
            }
            cnt++;
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto &x: blocked) {
            block.insert(x);
        }
        int maxArea = (blocked.size() * blocked.size())/ 2;
        return solve(maxArea,source,target) && solve(maxArea,target,source);
    }
};