#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int dp[m+1][n+1]; // dp[i][j] - number of deletions required to make
                          // the two strings the same up to the i-1th index
                          // of s1 and j-1th index of s2. 
        memset(dp, 0, sizeof(dp));
        
        
        for(int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        
        for(int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                // If the current characters of both strings are the
                // same, the number of deletions required is the same
                // as the one needed for the characters at the previous
                // index
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                // If they are different, the number of deletions required
                // is the minimum deletion required at the previous index
                // plus 1
                else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};
