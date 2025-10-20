#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) {
            return {};
        }
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i = 0; i < p.size(); i++) {
            freq1[p[i] - 'a']++;
            freq2[s[i] - 'a']++;
        }
        vector<int>ans;
        if(freq1 == freq2) {
            ans.push_back(0);
        }
        for(int i = p.size(); i < s.size(); i++) {
            freq2[s[i - p.size()] - 'a']--;
            freq2[s[i] - 'a']++;
            if(freq1 == freq2) {
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;
    }
};