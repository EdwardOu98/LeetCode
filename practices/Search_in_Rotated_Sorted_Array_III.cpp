#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            // Because when there are multiple target elements exist,
            // we want the left-most one, we return the index when 
            // the left element is equal to target
            if(nums[l] == target) {
                return l;
            }
            // When the mid element is equal to target, we set r to mid
            // and try to find another same element with smaller index
            else if(nums[mid] == target) {
                r = mid;
            }
            else if(nums[mid] > nums[l]) {
                if(nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if(nums[mid] < nums[r]) {
                if(nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                while(l <= r && nums[mid] == nums[l]) {
                    ++l;
                }
                while(l <= r && nums[r] == nums[mid]) {
                    --r;
                }
            }6
        }
        
        return -1;
    }
};
