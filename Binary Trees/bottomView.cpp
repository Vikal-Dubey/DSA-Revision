#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.size()) {
            auto [node,d]  = q.front();
            q.pop();
            mp[d] = node->data;
            if(node->left) {
                q.push({node->left,d-1});
            }
            if(node->right) {
                q.push({node->right,d+1});
            }
        }
        vector<int>ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};