#include <vector>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        
        int count = 0;
        
        for(int move = 1; move <= maxMove; ++move) {
            vector<vector<int>> tmp(m, vector<int>(n, 0));
            
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(i == 0) {
                        count = (count + dp[i][j]) % MOD;
                    }
                    if(j == 0) {
                        count = (count + dp[i][j]) % MOD;
                    }
                    if(i == m - 1) {
                        count = (count + dp[i][j]) % MOD;
                    }
                    if(j == n - 1) {
                        count = (count + dp[i][j]) % MOD;
                    }
                    
                    tmp[i][j] = (((i ? dp[i-1][j] : 0) + (i < m - 1 ? dp[i+1][j] : 0)) % MOD + 
                                 ((j ? dp[i][j-1] : 0) + (j < n - 1 ? dp[i][j+1] : 0)) % MOD) % MOD;
                }
            }
            
            dp = tmp;
        }
        
        return count;
    }
};
