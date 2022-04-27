#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // position where 0 occurs
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] != 0) {
                // If we see a non-zero number and 
                // its index is different from j, 
                // we swap the current number with
                // the 0 at j
                if(i != j) {
                    swap(nums[i], nums[j]);
                }
                ++j;
            }
        }
    }
};
