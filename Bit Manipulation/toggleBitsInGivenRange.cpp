#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int toggleBits(int n, int l, int r) {
        // code here
        for(int i = l; i <= r; i++) {
            n = n ^ (1 <<(i-1));
        }
        return n;
    }
    int toggleBits(int n, int l, int r) {
        // code here
        int len = r - l + 1;
        int mask = (1 << len) - 1;
        mask = (mask << (l-1));
        return n ^ mask;
    }
};
