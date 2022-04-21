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
        
        // If the first number is less than the last number,
        // then the input array is unrotated, return nums[low]
        if(nums[low] < nums[high]) {
            return nums[low];
        }
        
        while(low < high) {
            mid = low + (high - low) / 2;
            
            // If the mid element is larger than the last
            // element in the window, we need to search for
            // the head of the unrotated array on the right
            // side of the mid element
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // If the mid element is smaller than the last
            // element in the window, we need to search for
            // the head of the unrotated array on the left
            // side of the mid element
            else if(nums[mid] < nums[high]) {
                high = mid;
            }
            // If the mid element is equal to the last element
            // in the window, we have to linearly search for
            // the head of the unrotated array
            else {
                --high;
            }
        }
        
        return nums[high];
    }
};
