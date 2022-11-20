using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        // The three factors
        int factors[3] = {2, 3, 5};
        for(int i = 0; i < 3 && n > 0; ++i) {
            // Continue to divide n by factors[i] until
            // the remainder of n / factors[i] is not 0
            while((n % factors[i]) == 0) {
                n /= factors[i];
            }
        }
        
        // If n has prime factors limited to 2, 3, and 5, 
        // after the for-loop n will become 1. 
        return n == 1;
    }
};
