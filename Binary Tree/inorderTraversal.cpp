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
        vector<int> inorderTraversal(TreeNode* root) {
            TreeNode* curr = root;
            vector<int> ans;
            while(curr){
                if(curr->left){
                    TreeNode* pred = curr->left;
                    while(pred->right && pred->right != curr){
                        pred = pred->right;
                    }
                    if(pred->right == NULL){//link
                        pred->right = curr;
                        curr = curr->left;
                    }
                    else{//unlink   pred->right = curr.
                        pred->right = NULL;
                        ans.push_back(curr->val);
                        curr = curr->right;
                    }
                }
                else{
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            return ans;
        }
    };
    return 0;
}