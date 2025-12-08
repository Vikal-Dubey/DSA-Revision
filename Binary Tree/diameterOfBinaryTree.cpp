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
        int dfs(TreeNode* root,int& maxDia) {
            if(!root)   return 0;
            int leftHeight = dfs(root->left,maxDia);
            int rightHeight = dfs(root->right,maxDia);
            maxDia = max(maxDia,leftHeight + rightHeight);
            return 1 + max(leftHeight,rightHeight);
        } 
        int diameterOfBinaryTree(TreeNode* root) {
            int maxDia = 0;
            dfs(root,maxDia);
            return maxDia;
        }
    };
    return 0;
}