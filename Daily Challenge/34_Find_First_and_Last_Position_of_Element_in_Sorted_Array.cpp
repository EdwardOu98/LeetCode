#include <vector>

using namespace std;

class Solution {
private:
    int searchFirst(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                if(mid == 0 || nums[mid] != nums[mid - 1]) {
                    return mid;
                }
                else {
                    r = mid - 1;
                }
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
    
    int searchLast(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                if(mid == n - 1 || nums[mid] != nums[mid + 1]) {
                    return mid;
                }
                else {
                    l = mid + 1;
                }
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) {
            return {-1, -1};
        }
        
        return {searchFirst(nums, target), searchLast(nums, target)}; 
    }
};
