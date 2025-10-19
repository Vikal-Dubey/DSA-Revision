#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string s, string g) {
        vector<int>mp(10,0);
        for(auto it : s) {
            mp[it-'0']++;
        }
        int cntB = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == g[i]) {
                cntB++;
                mp[s[i]-'0']--;
            }
        }
        int cntC = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == g[i])    continue;
            if(mp[g[i] - '0']) {
                cntC++;
                mp[g[i] - '0']--;
            }
        }
        return to_string(cntB) + 'A' + to_string(cntC) + 'B';
    }
};