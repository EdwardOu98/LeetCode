#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0; // Record how many numbers we added
                       // to the array
        int i = 0; // Array index
        int m = nums.size(); // Array size
        long maxNum = 0; // The maximum number that can be formed by the sum
                         // of sum elements in the array
        
        while(maxNum < n) {
            // If we are still inside the array and the current element is smaller
            // than or equal to the previous maximum number plus 1, then the next
            // maximum number is the previous maximum plus the current element
            if(i < m && nums[i] <= maxNum + 1) {
                maxNum += nums[i++];
            }
            // Otherwise, we have to insert the previous maximum number plus 1
            // into the array
            else {
                maxNum += maxNum + 1;
                ++count;
            }
        }
        
        return count;
    }
};
