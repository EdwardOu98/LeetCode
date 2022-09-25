using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const long MOD = 1e9 + 7;
        long res = 0, len = 0;
        
        for(int i = 1; i <= n; ++i) {
            // When the current number is a power of 2, 
            // increment the length of shifts. This length
            // is equivalent to the length of binary form
            // of the number we need to concatenate
            if((i & (i-1)) == 0) {
                ++len;
            }
            
            res = ((res << len) % MOD + i) % MOD;
        }
        
        return res;
    }
};
