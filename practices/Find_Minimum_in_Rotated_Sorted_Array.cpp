#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        int low = 0, high = n - 1, mid;
        
        // If nums[low] is less than nums[high], then the part
        // from low to high is not rotated, and the minimum of
        // the entire array falls on nums[low];
        if(nums[high] > nums[0]) {
            return nums[0];
        }
        
        while(low <= high) {
            
            mid = low + (high - low) / 2;
            
            // If the mid element is greater than its next element,
            // it means we have found the tail of the unrotated array.
            // Thus, we can return mid's next element because it is
            // the head of the unrotated array
            if(nums[mid] > nums[mid+1]) {
                return nums[mid+1];
            }
            
            // If the mid element is less than its previous element,
            // it means we have found the head of the unrotated array.
            // Thus, we can return it
            if(nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            
            // If the mid element is greatere than the last element of
            // the window, we need to search for the original head
            // on the right side of mid
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // If the mid element is smaller than the last element of 
            // the window, we need to search for the original head
            // on the left side of mid;
            else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};
