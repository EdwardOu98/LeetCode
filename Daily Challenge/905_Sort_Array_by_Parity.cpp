#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums;
        }
        int i = 0, j = 0; // i is the loop variable, and j is the position of
                          // the odd elements
        
        while(i < n) {
            // If we see an even element, we swap it with the earliest odd 
            // element we found
            if((nums[i] % 2) == 0) {
                swap(nums[i], nums[j]);
                ++j;
            }
            // If we found an odd element, we proceed to check the next element
            ++i;
        }
        
        return nums;
    }
};
