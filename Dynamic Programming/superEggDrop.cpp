#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dp;
    int minSteps(int k,int n) {
        if(n <= 1 || k == 1)  return n;
        if(dp[n][k] != -1)  return dp[n][k];
        int ans = INT_MAX;
        int lo = 0,hi = n;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int breakCase = minSteps(k-1,mid-1);
            int notBreakCase = minSteps(k,n - mid);
            
            if(breakCase < notBreakCase) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
            ans = min(ans,1 + max(breakCase,notBreakCase));
        }
        return dp[n][k] = ans;
    }
    int superEggDrop(int k, int n) {
        dp.resize(n+2,vector<int>(k+2,-1));
        return minSteps(k,n);
    }
};