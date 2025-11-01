#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dp;
    bool isPalin(string &s,int i,int j) {
        if(i >= j) {
            return 1;
        }
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == s[j]) {
            return dp[i][j] = isPalin(s,i+1,j-1);
        }
        else return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(isPalin(s,i,j)) {
                    if(j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};