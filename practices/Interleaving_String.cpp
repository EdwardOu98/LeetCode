#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if(s3.length() != m + n){
            return false;
        }

        bool dp[m+1][n+1];

        for(int i = 0; i <= m; ++i) {
            for(int j = 0; j <= n; ++j) {
                // When all 3 strings are empty, s3 is an interleaving
                // string of s1 and s2
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                // When s1 is empty, check whether s3's previous character
                // comes from s2 and whether their current character matches
                else if(i == 0) {
                    dp[i][j] = dp[i][j-1] && (s3[i+j-1] == s2[j-1]);
                }
                // When s2 is empty, check whether s3's previous character
                // comes from s1 and whether their current character matches
                else if(j == 0) {
                    dp[i][j] = dp[i-1][j] && (s3[i+j-1] == s1[i-1]);
                }
                // When s1 and s2 are not empty, check whether s3's previous
                // character comes from s1/s2 and whether the current character
                // of s3 and s1/s2 matches
                else {
                    dp[i][j] = (dp[i][j-1] && (s3[i+j-1] == s2[j-1])) ||
                                (dp[i-1][j] && (s3[i+j-1] == s1[i-1]));
                }
            }
        }

        return dp[m][n];
    }
};
