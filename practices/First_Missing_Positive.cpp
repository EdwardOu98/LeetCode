#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i;
        
        for(i = 0; i < n; ++i) {
            while(nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(i = 0; i < n; ++i) {
            if((i + 1) != nums[i]) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};
