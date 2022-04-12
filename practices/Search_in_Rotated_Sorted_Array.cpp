#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        
        while(l <= r) {
            if(nums[l] == target) {
                return l;
            }
            else if(nums[r] == target) {
                return r;
            }
            mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > nums[l]) {
                if(nums[l] < target && nums[mid] > target) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if(nums[mid] < nums[r]) {
                if(nums[mid] < target && nums[r] > target) {
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
            }
        }
        
        return -1;
    }
};
