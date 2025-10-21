#include<bits/stdc++.h>
using namespace std;
// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)  return 0;
        vector<bool>sieve(n,1); //1 means prime
        sieve[0] = 0;
        sieve[1] = 0;
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(sieve[i]) {
                count++;
                for(int j = 2 * i; j < n; j += i) {
                    sieve[j] = 0;
                }
            }
        }
        return count;
    }
};