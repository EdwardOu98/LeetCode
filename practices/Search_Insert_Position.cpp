#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                if(mid == n - 1 || nums[mid + 1] >= target) {
                    return mid + 1;
                }
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return l;
    }
};
