#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) {
            return {};
        }
        vector<vector<int>> res;
        
        int i, j, l, r;         // Loop varaibles
        int lnum, rnum;         // Two of the numbers
        int sum1, sum2, sum3;   // Intermediate results
        
        // Sort the input array to simplify the process of handling repeating elements
        sort(nums.begin(), nums.end());
        
        for(i = 0; i < n; ++i) {
            // If the current number is the same as the last handled number, we
            // skip to the next round without executing the remaining part of the
            // outer-most loop
            if(i && nums[i] == nums[i-1]) {
                continue;
            }
            
            sum1 = target - nums[i];
            for(j = i + 1; j < n; ++j) {
                // If the current number is the same as the last handled number, we
                // skip to the next round without executing the remaining part of the
                // second outer-most loop
                if(j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                
                sum2 = sum1 - nums[j];
                
                // Use the two-pointer technique to find the other two numbers
                l = j + 1;
                r = n - 1;
                
                while(l < r) {
                    lnum = nums[l];
                    rnum = nums[r];
                    
                    sum3 = lnum + rnum;
                    
                    // If the sum of the current two numbers are too small, we 
                    // change the left number to a larger one and skips through
                    // the repeating ones
                    if(sum3 < sum2) {
                        while((l < r) && (nums[l] == lnum)) {
                            ++l;
                        }
                    }
                    // If the sum of the current two numbers are too large, we 
                    // change the right number to a smallerer one and skips through
                    // the repeating ones
                    else if(sum3 > sum2) {
                        while((l < r) && (nums[r] == rnum)) {
                            --r;
                        }
                    }
                    // If the sum of the current two numbers are equal to our target,
                    // we push all four numbers into the result array, and change the
                    // left and right boundaries accordingly
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while((l < r) && (nums[l] == lnum)) {
                            ++l;
                        }
                        while((l < r) && (nums[r] == rnum)) {
                            --r;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
