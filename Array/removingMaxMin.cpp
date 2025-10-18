#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIdx = -1;
        int maxEle = INT_MIN;
        int minIdx = -1;
        int minEle = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxEle) {
                maxEle = nums[i];
                maxIdx = i;
            }
            if(nums[i] < minEle) {
                minEle = nums[i];
                minIdx = i;
            }
        }
        int front = max(maxIdx,minIdx) + 1;
        int back = nums.size() - min(maxIdx,minIdx);
        int both = min(minIdx,maxIdx) + 1 + nums.size() - max(maxIdx,minIdx);
        return min({front,back,both});
    }
};