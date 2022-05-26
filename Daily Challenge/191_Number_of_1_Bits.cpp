#include <cstdint>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            n &= (n - 1); // This will set the lowest 1 to 0
            ++res;
        }
        
        return res;
    }
};
