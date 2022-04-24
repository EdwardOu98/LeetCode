#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));  // When text1 and text2 are empty
                                    // strings, the longest common
                                    // subsequence is 0

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                // If the current character of both strings matches, dp[i][j] = dp[i-1][j-1] + 1.
                // If they doesn't match, dp[i][j] will be the maximum between dp[i-1][j] and dp[i][j-1]
                dp[i][j] = (text1[i-1] == text2[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};
