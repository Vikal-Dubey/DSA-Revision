#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_set<char>st;
        int maxLen = 0;
        while(r < s.size()) {
            if(!st.count(s[r])) {
                st.insert(s[r]);
                int x = st.size();
                maxLen = max(maxLen,x);
                r++;
            }
            else {
                st.erase(s[l]);
                l++;
            }
        }
        return maxLen;
    }
};