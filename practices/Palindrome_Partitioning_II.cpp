#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length(), i, j;
        int dp[n];
        for(i = 0; i < n; ++i) {
            dp[i] = i;
        }
        
        for(i = 0; i < n; ++i) {
            // Use the current character as pivot, check whether the left
            // and right part of the string can form a palindrome. If a 
            // Palindrome is found, check whether the left border of the
            // palindrome is 0. If it's 0, then we can form a palindrome
            // without making a cut, which means dp[i+j] = 0. Otherwise, we
            // pick the smaller number of cut between the left and right
            // and right border.
            for(j = 0; (i - j) >= 0 && (i + j) < n && s[i-j] == s[i+j]; ++j) {
                dp[i+j] = ((i-j) == 0) ? 0 : min(dp[i-j-1] + 1, dp[i+j]);
            }
            
            // Use the space between the current character and the previous character
            // as pivot, repeat the above steps.
            for(j = 0; (i - j - 1) >= 0 && (i + j) < n && s[i-j-1] == s[i+j]; ++j) {
                dp[i+j] = ((i-j-1) == 0) ? 0 : min(dp[i-j-2] + 1, dp[i+j]);
            }
        }
        
        return dp[n-1];
    }
};
