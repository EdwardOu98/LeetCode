#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size(), i = 0;
        
        // We make use of the properties of XOR:
        // - Any number XOR with itself is 0
        // - Any number XOR with 0 is the number itself
        // - We can reorder the sequence of XOR and still get the correct result
        // In the for-loop, we XOR all numbers in the range [0, n] twice except
        // the missing number.
        for(int num : nums) {
            res ^= num ^ i;
            ++i;
        }
        
        return res;
    }
};
