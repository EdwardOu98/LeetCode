#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        // If both strings are empty, they always match
        dp[0][0] = true;
        int i, j;
        
        // If the input string s is empty, the two strings 
        // matches only if the current character of the pattern
        // string is '*'
        for(j = 0; j < n && p[j] == '*'; ++j) {
            dp[0][j + 1] = true;
        }
        
        for(i = 1; i <= m; ++i) {
            for(j = 1; j <= n; ++j) {
                // If the current character of the pattern string is '*',
                // the two string matches if dp[i-1][j], which means s[0...i-2]
                // and p[0...j-1] matches and the '*' can match one more character;
                // or dp[i][j-1], which means s[0...i-1] and p[0...j-2] matches, and
                // the '*' can match an empty sequence. 
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                // If the current character of the pattern string is anything other than
                // '*', we simply check if s[i-1] == p[j-1] or p[j-1] == '?', then AND with
                // the previous result
                else {
                    dp[i][j] = ((s[i-1] == p[j-1]) || (p[j-1] == '?')) && dp[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
};
