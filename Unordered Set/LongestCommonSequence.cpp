#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        unordered_set<int>st;
        for(auto it : nums) st.insert(it);
        int ans = 0;
        for(auto it : st) {
            if(!st.count(it-1)) {
                int count = 1;
                int x = it;
                while(st.count(x+1)) {
                    x++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};