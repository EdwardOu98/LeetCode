#include <string.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        int temp = num;
        int n = 0;      // number of digits in num
        while(temp > 0) {
            temp /= 10;
            ++n;
        }

        // If there's only 1 digit in num, then there's
        // only one way to decode
        if(n < 2) {
            return 1;
        }

        int dp[n+1];                // dp array
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;                  // 1 way to decode if num is empty
        dp[n - 1] = 1;              // 1 way to decode for 1 digit

        int i = n - 2;
        while(num > 0 && i >= 0) {
            temp = num % 10;                // Take the last one digit from num and decode
            if(0 <= temp && temp <= 9) {
                dp[i] += dp[i + 1];
            }

            temp = num % 100;               // Take the last two digit from num and decode
            if(10 <= temp && temp <= 25) {
                dp[i] += dp[i + 2];
            }
            num /= 10;
            --i;
        }

        return dp[0];
    }
};
