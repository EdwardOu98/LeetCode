#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // If input array is empty, then no need to search
        if(nums.empty()) {
            return false;
        }
        int n = nums.size(); // Size of input array
        int low = 0, high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2; // Prevent overflow
            if(nums[mid] == target || nums[low] == target || nums[high] == target) {
                return true;
            }
            // The current mid point of the input array belongs to the
            // first part of the input array
            if(nums[mid] > nums[low]) {
                // If target falls between low and mid, set high = mid - 1;
                // Otherwise, set low = mid + 1
                if(nums[low] < target && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            // The current mid point of the input array belongs to the
            // second part of the input array
            else if(nums[mid] < nums[high]) {
                // If target falls between mid and high, set low = mid + 1;
                // Otherwise set high = mid - 1
                if(nums[mid] < target && target < nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            // If the current mid point of the input array is equal to either
            // the low or the high or both elements, then we are not able to identify
            // which part it really belongs to. In this case, we have to change low and
            // high iteratively.
            else {
                while(low <= high && nums[mid] == nums[low]) {
                    ++low;
                }
                while(low <= high && nums[mid] == nums[high]) {
                    --high;
                }
            }
        }
        
        return false;
    }
};
