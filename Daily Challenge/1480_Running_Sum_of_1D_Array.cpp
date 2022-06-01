#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Calculate prefix sum up to the i-th element (inclusive)
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        
        return nums;
    }
};
