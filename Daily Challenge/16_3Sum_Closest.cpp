#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        int minDiff = INT_MAX, currDiff;
        int n = nums.size();
        int i, j, k, sum, lnum, rnum;
        sort(nums.begin(), nums.end());
        
        for(i = 0; i < n; ++i) {
            j = i + 1;
            k = n - 1;
            
            while(j < k) {
                lnum = nums[j];
                rnum = nums[k];
                sum = nums[i] + lnum + rnum;
                if(sum == target) {
                    return sum;
                }
                currDiff = abs(sum - target);
                
                if(currDiff < minDiff) {
                    ret = sum;
                    minDiff = currDiff;
                }
                
                if(sum < target) {
                    while(j < k && nums[j] == lnum) {
                        ++j;
                    }
                }
                else {
                    while(j < k && nums[k] == rnum) {
                        --k;
                    }
                }
            }
        }
        
        return ret;
    }
};
