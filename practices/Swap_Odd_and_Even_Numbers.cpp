#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return nums;
        }
        int j = 0;

        for(int i = 0; i < n; ++i) {
            if(nums[i] % 2) {
                if(i != j) {
                    swap(nums[i], nums[j]);
                }
                ++j;
            }
        }

        return nums;
    }
};
