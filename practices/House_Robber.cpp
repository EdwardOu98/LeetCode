#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return nums[0];
        }

        int odd = 0, even = 0;
        for(int i = 0; i < n; ++i) {
            // If we are on an odd index, the maximum amount
            // of money we can rob is either the previous 
            // amount of money we rob from the even-indexed
            // houses or that from the odd-indexed houses 
            // plus the current house's money. 
            if(i % 2) {
                odd = max(even, odd + nums[i]);
            }
            // Similarly, the maximum amount of money we can
            // rob on an even index is either the previous
            // amount of money we rob from the odd-indexed
            // houses or that from the even-indexed houses
            // plus the current house's money
            else {
                even = max(odd, even + nums[i]);
            }
        }

        return max(odd, even);
    }
};
