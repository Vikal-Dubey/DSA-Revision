#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>>q;
        q.push({0});
        int target = graph.size() - 1;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int node = curr.back();
            if(node == target) {
                ans.push_back(curr);
            } else {
                for(auto it : graph[node]) {
                    vector<int>temp = curr;
                    temp.push_back(it);
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};