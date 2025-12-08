#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class Solution {
    public:
        vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
            int maxOne = 0;
            int idx = 0;
            for(int i = 0; i < mat.size(); i++) {
                int cntOne = 0;
                for(int j = 0; j < mat[0].size(); j++) {
                    if(mat[i][j] == 1) {
                        cntOne++;
                    }
                }
                if(cntOne > maxOne) {
                    maxOne = cntOne;
                    idx = i;
                }
            }
            return {idx, maxOne};
        }
    };
    return 0;
}