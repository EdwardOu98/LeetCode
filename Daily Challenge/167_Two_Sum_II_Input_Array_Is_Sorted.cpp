#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, sum;
        
        while(l < r) {
            sum = nums[l] + nums[r];
            if(sum == target) {
                return {l+1, r+1};
            }
            else if(sum < target) {
                ++l;
            }
            else {
                --r;
            }
        }
        
        return {};
    }
};
