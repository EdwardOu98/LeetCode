#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int arrSize = max(1, n + 1);
        int dp[arrSize]; // dp[i] means to sum up to i how many 
                         // perfect square numbers we need
        dp[0] = 0; // To sum up to 0, we don't need any number
        for(int i = 1; i < arrSize; ++i) {
            dp[i] = INT_MAX;
        }
        
        for(int i = 1; i * i <= n; ++i) {
            for(int j = i * i; j <= n; ++j) {
                if(dp[j] > dp[j - i * i] + 1) {
                    dp[j] = dp[j - i * i] + 1;
                }
            }
        }
        
        return dp[n];
    }
};
