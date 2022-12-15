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
            if(i % 2) {
                odd = max(even, odd + nums[i]);
            }
            else {
                even = max(odd, even + nums[i]);
            }
        }
        
        return max(odd, even);
    }
};
