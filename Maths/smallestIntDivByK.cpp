#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 00) {
            return -1;
        }
        int n = 1;
        int cnt = 1;
        while(n % k!= 0) {
            n = (n * 10 + 1) % k;
            cnt++;
        }
        return cnt;
    }
};