#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) {
            return 0;
        }
        
        int N = s.length();
        int dp[N + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        if(s[0] == '0') {
            dp[1] = 0;
        }
        else {
            dp[1] = 1;
        }
        
        int temp;
        for(int i = 2; i <= N; ++i) {
            temp = stoi(s.substr(i-1, 1));
            if(1 <= temp && temp <= 9) {
                dp[i] += dp[i-1];
            }
            
            temp = stoi(s.substr(i-2, 2));
            if(10 <= temp && temp <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[N];
    }
};
