#include <vector>

using namespace std;

class Solution {
private:
    int countNumbers(vector<int>& nums, int target) {
        int count = 0;      // Record the count of numbers less than or equal to target
        for(int& num : nums) {
            if(num <= target) {
                ++count;
            }
        }
        
        return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size(), mid;
        int duplicate = -1;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            
            // If the count of numbers less than or equal to mid
            // is greater than mid, that means the duplicate number
            // must be smaller than or equal to mid. Thus, we record
            // the current number and try to find a smaller number 
            // that meets the same condition
            if(countNumbers(nums, mid) > mid) {
                duplicate = mid;
                high = mid - 1;
            }
            // Otherwise, the duplicate must be greater than
            // mid. Thus, we should find the duplicate number
            // on the right side of mid
            else {
                low = mid + 1;
            }
        }
        
        return duplicate;
    }
};
