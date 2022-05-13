#include <algorithm>

using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        int counter[32] = {0};
        int idx = 0, maxLen = 0;
        unsigned int n = num; // Convert the input to unsigned 
                              // to handle negative inputs
        while(n != 0) {
            // If the current bit is 1, we increment the 
            // counter. Otherwise we increment the index
            if((n & 1) == 1) {
                ++counter[idx];
            }
            else {
                ++idx;
            }
            n >>= 1;
        }

        for(int i = 0; i < 31; ++i) {
            maxLen = max(maxLen, counter[i] + counter[i+1] + 1);
        }

        return min(maxLen, 32);
    }
};
