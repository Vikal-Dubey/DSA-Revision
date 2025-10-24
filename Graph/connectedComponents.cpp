#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_set<int>& vis,unordered_map<int,vector<int>>& adj,int node) {
        vis.insert(node);
        for(auto it : adj[node]) {
            if(!vis.count(it)) {
                dfs(vis,adj,it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int cc = 0;
        unordered_map<int,vector<int>>adj;
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_set<int>vis;
        for(int i = 0; i < n; i++) {
            if(!vis.count(i)) {
                cc++;
                dfs(vis,adj,i);
            }
        }
        return cc;
    }
};
