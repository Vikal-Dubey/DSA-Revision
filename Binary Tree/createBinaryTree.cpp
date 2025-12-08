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
        TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
            unordered_map<int, TreeNode*> mp;
            unordered_set<int> child;

            for (auto &d : descriptions) {
                int p = d[0], c = d[1], isLeft = d[2];

                if (!mp[p]) mp[p] = new TreeNode(p);
                if (!mp[c]) mp[c] = new TreeNode(c);

                if (isLeft) mp[p]->left = mp[c];
                else mp[p]->right = mp[c];

                child.insert(c);
            }

            int rootVal = -1;
            for (auto &d : descriptions) {
                int p = d[0];
                if (!child.count(p)) {
                    rootVal = p;
                    break;
                }
            }

            return mp[rootVal];
        }
    };

    return 0;
}