#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return 0;
        }
        int low = 0, high = n - 1, mid;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            // If the mid element is on a falling edge (nums[mid] > nums[mid+1]),
            // then we should search for the peak on the left side of the mid element
            if(nums[mid] > nums[mid+1]) {
                high = mid;
            }
            // If the mid element is on a rising edge (nums[mid] < nums[mid+1]),
            // then we should search for the peak on the right side of the mid element
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
