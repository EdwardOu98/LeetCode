#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Get length of s1 and s2
        int m = s1.length(), n = s2.length();
        
        // If the length of s3 is not equal to the sum of s1's and s2's length,
        // then it cannot be the interleaving of s1 and s2
        if(s3.length() != m + n) {
            return false;
        }
        
        bool dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        
        for(int i = 0; i <= m; ++i) {
            for(int j = 0; j <= n; ++j) {
                // If both strings are empty, then they can surely form an empty string
                if((i == 0) && (j == 0)) {
                    dp[i][j] = true;
                }
                // If s1 is empty, then we need to check whether the current character
                // of s3 matches with the current character of s2
                else if(i == 0) {
                    dp[i][j] = dp[i][j-1] && s3[i+j-1] == s2[j-1];
                }
                // If s2 is empty, then we need to check whether the current character
                // of s3 matches with the current character of s1
                else if(j == 0) {
                    dp[i][j] = dp[i-1][j] && s3[i+j-1] == s1[i-1];
                }
                // If both string are not empty, check whether the current character of s3
                // matches with the current character of s1 or s2
                else {
                    dp[i][j] = (dp[i][j-1] && s3[i+j-1] == s2[j-1]) ||
                               (dp[i-1][j] && s3[i+j-1] == s1[i-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};
