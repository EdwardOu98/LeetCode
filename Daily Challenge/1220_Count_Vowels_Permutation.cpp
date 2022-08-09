#include <vector>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long> dp(5, 1LL), prev(5, 1LL);
        const int MOD = 1e9 + 7;
        const int a = 0, e = 1, i = 2, o = 3, u = 4;
        
        while(n-- > 1) {
            dp[a] = (prev[e] + prev[i] + prev[u]) % MOD;
            dp[e] = (prev[a] + prev[i]) % MOD;
            dp[i] = (prev[e] + prev[o]) % MOD;
            dp[o] = prev[i];
            dp[u] = (prev[i] + prev[o]) % MOD;
            dp.swap(prev);
        }
        
        long long res = 0;
        for(int i = 0; i < 5; ++i) {
            res = (res + prev[i]) % MOD;
        }
        
        return res;
    }
};
