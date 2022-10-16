#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int D) {
        int n = jobDifficulty.size();
        if(D > n) {
            return -1;
        }
        
        int dp[D][n];
        dp[0][0] = jobDifficulty[0];
        for(int i = 1; i < n; ++i) {
            dp[0][i] = max(jobDifficulty[i], dp[0][i-1]);
        }
        
        for(int d = 1; d < D; ++d) {
            for(int len = d; len < n; ++len) {
                int localMax = jobDifficulty[len];
                dp[d][len] = INT_MAX;
                for(int i = len; i >= d; --i) {
                    localMax = max(localMax, jobDifficulty[i]);
                    dp[d][len] = min(dp[d][len], dp[d-1][i-1] + localMax);
                }
            }
        }
        
        return dp[D-1][n-1];
    }
};
