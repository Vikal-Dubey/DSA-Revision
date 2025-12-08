#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    
    class Solution {
    public:
        int level(TreeNode* root){
            if(root == NULL)    return 0;
            return 1 + max(level(root->left),level(root->right));
        }
        void nthOrder(vector<int>& ans,TreeNode* root,int curr,int idx){
            if(root == NULL)    return;
            if(curr == idx){
                ans[curr] = root->val;
                return;
            }
            nthOrder(ans,root->left,curr+1,idx);
            nthOrder(ans,root->right,curr+1,idx);
        }
        vector<int> rightSideView(TreeNode* root) {
            int n = level(root);
            vector<int> ans(n,0);
            for(int i = 0;i<n;i++){
                nthOrder(ans,root,0,i);     
            }
            return ans;
        }
    };
    return 0;
}