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
        
        // Use binary search to find the target number
        while(low <= high) {
            mid = low + (high - low) / 2; // Prevent overflow
            
            // If the current target has a count of numbers less than or equal to itself
            // that is greater than itself, we set the current target as the duplicated number.
            // Then try to find a smaller one by lowering the upper boundary of the search region. 
            if(countNumbers(nums, mid) > mid) {
                duplicate = mid;
                high = mid - 1;
            }
            // Otherwise, we raise the lower boundary
            else {
                low = mid + 1;
            }
            
        }
        
        return duplicate;   // The final result is the smallest number with a count of numbers
                            // less than or equal to itself that is greater than the number itself
    }
};
