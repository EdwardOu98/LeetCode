#include <vector>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    int permutations(int n) {
        long res = 1;
        // Calculate ways to arrange pickup and delivery orders
        for(int i = 1; i <= n; ++i) {
            res *= i;   // There are n! ways to arrange pickups
            res *= (2 * i - 1); // There are (2 * n - 1)! ways to arrange deliveries
            res %= MOD;
        } 
        
        return res;
    }
    
    int bottomUpDP(int n) {
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));
        
        for(int unpicked = 0; unpicked <= n; ++unpicked) {
            for(int undelivered = unpicked; undelivered <= n; ++undelivered) {
                if(unpicked == 0 && undelivered == 0) {
                    dp[unpicked][undelivered] = 1;
                    continue;
                }
                
                if(unpicked > 0) {
                    dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];
                }
                dp[unpicked][undelivered] %= MOD;
                
                if(undelivered > unpicked) {
                     dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];
                }
                 dp[unpicked][undelivered] %= MOD;
            }
        }
        
        return dp[n][n];
    }
    
    int topDownDP(int n) {
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));
        return topDownHelper(dp, n, n);
    }
    
    long topDownHelper(vector<vector<long>>& dp, int unpicked, int undelivered) {
        if(unpicked == 0 && undelivered == 0) {
            return 1;
        }
        
        if(unpicked < 0 || undelivered < 0 || undelivered < unpicked) {
            return 0;
        }
        
        if(dp[unpicked][undelivered]) {
            return dp[unpicked][undelivered];
        }
        long res = 0;
        
        res += unpicked * topDownHelper(dp, unpicked - 1, undelivered);
        res %= MOD;
        
        res += (undelivered - unpicked) * topDownHelper(dp, unpicked, undelivered - 1);
        res %= MOD;
        
        return dp[unpicked][undelivered] = res;
    }
    
    int probability(int n) {
        long res = 1;
        
        for(int i = 1; i <= 2 * n; ++i) {
            res = res * i;
            
            if(i % 2 == 0) {
                res /= 2;
            }
            
            res %= MOD;
        }
        return res;
    }
public:
    int countOrders(int n) {
        // return probability(n);
        // return topDownDP(n);
        // return bottomUpDP(n);
        return permutations(n);
    }
};
