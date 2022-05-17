#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }

        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            // If the current index is odd and the current number is 
            // greater than its previous number, swap their position
            if((i % 2) && nums[i] > nums[i-1]) {
                swap(nums[i], nums[i-1]);
            }
            // If the current index is even and the current number is 
            // less than its previous number, swap their position
            else if((i % 2 == 0) && nums[i] < nums[i-1]) {
                swap(nums[i], nums[i-1]);
            }
        }
    }
};
