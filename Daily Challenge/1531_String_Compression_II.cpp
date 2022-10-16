#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int dp[101][27][11][101]; // dp[current_index][last_char][count_of_char][k]
    int n; // Length of s
    
    int helper(string& s, int curr, char last, int count, int k) {
        if(k < 0) {
            return 101;
        }
        if(curr >= n) {
            return 0;
        }
        if(count >= 10) {
            count = 10;
        }
        
        if(dp[curr][last - 'a'][count][k] != -1) {
            return dp[curr][last - 'a'][count][k];
        }
        
        int res = 101;
        
        // delete the current character
        res = helper(s, curr + 1, last, count, k - 1);
        
        // Keep the current character
        if(s[curr] != last) {
            res = min(res, 1 + helper(s, curr + 1, s[curr], 1, k));
        }
        else {
            if(count == 1 || count == 9) {
                res = min(res, 1 + helper(s, curr + 1, last, count + 1, k));
            }
            else {
                res = min(res, helper(s, curr + 1, last, count + 1, k));
            }
        }
        
        return dp[curr][last - 'a'][count][k] = res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        if(n == 100) {
            bool allSame = true; // Check whether all characters in s are the same
            for(int i = 1; i < n; ++i) {
                if(s[i] != s[i-1]) {
                    allSame = false;
                    break;
                }
            }
            // If all the characters are the same, then the string can be compressed
            // to "a100", which has length of 4
            if(allSame) {
                return 4;
            }
        }
        
        // If we can delete all the characters, then we will have an empty string
        if(k >= n) {
            return 0;
        }
        
        // Initialize the dp array
        for(int i = 0; i < 101; ++i) {
            for(int j = 0; j < 27; ++j) {
                for(int p = 0; p < 11; ++p) {
                    for(int q = 0; q < 101; ++q) {
                        dp[i][j][p][q] = -1;
                    }
                }
            }
        }
        
        return helper(s, 0, 'z' + 1, 0, k);
    }
};
