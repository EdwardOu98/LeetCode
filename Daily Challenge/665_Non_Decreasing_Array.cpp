#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int modified = 0;
        
        for(int i = 1; i < n && modified <= 1; ++i) {
            // If the previous element is greater than the current element
            if(nums[i-1] > nums[i]) {
                // Increment the modified element count
                ++modified;
                // Modify the previous element with higher priority to avoid
                // inversion error after i
                if((i - 2 < 0) || (nums[i-2] <= nums[i])) {
                    nums[i-1] = nums[i];
                }
                else {
                    nums[i] = nums[i-1];
                }
            }
        }
        
        return modified <= 1;
    }
};
