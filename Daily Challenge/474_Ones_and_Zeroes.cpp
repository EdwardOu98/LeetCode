#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int num0, num1; // Number of 0's and 1's in the array of strings
        
        // Count the total number of 0's and 1's in the array
        for(string& s : strs) {
            num0 = num1 = 0;
            for(char c : s) {
                if(c == '0') {
                    ++num0;
                }
                else if(c == '1'){
                    ++num1;
                }
            }
            
            // dp[i][j] is the maximum number of strings to include
            // to form a subset with i 0's and j 1's
            for(int i = m; i >= num0; --i) {
                for(int j = n; j >= num1; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-num0][j-num1] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
