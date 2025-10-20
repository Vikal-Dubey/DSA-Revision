#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()) {
            auto [curr,d] = q.front();
            q.pop();
            if(!mp.count(d)) {
                mp[d] = curr->data;
            }
            if(curr->left) {
                q.push({curr->left,d-1});
            }
            if(curr->right) {
                q.push({curr->right,d+1});
            }
        }
        vector<int>ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};