#include <cstdlib>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // If dividend is INT_MIN and divisor is -1, return INT_MAX
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // If dividend is 0 or divisor is 1, return dividend
        if(dividend == 0 || divisor == 1) {
            return dividend;
        }
        // If divisor is -1, return -dividend (Because -INT_MAX > INT_MIN, there won't
        // be overflow)
        if(divisor == -1) {
            return -dividend;
        }
        
        // Sign of the result depends on the sign of the operands
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        int res = 0;
        // Use unsigned int to prevent overflow
        unsigned int ua = abs(dividend), ub = abs(divisor);
        
        for(int i = 31; i >= 0; --i) {
            // If the dividend is greater than the divisor, set
            // the current position to 1. Leave it as 0 otherwise. 
            if((ua >> i) >= ub) {
                ua -= (ub << i);
                res |= (1 << i);
            }
        }
        
        return sign > 0 ? res : -res;
    }
};
