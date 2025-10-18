#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(101,0);
        int maxFreq = 0;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            maxFreq = max(maxFreq,freq[nums[i]]);
        }
        int ans = 0;
        for(int i = 0 ;i < freq.size(); i++) {
            if(freq[i] == maxFreq) {
                ans += freq[i];
            }
        }
        return ans;
    }
};