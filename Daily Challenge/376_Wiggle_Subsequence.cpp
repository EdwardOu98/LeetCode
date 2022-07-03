#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // If the length of the input array is less than 2, return 
        // the length of the array
        if(n < 2) {
            return n;
        }
        
        int up = 1, down = 1;
        
        for(int i = 1; i < n; ++i) {
            // If the current element is greater than its previous
            // element, it's on an up position. Then its previous 
            // element must be a down position. In this case, the
            // length of the longest subsequence end with a down
            // position remains the same, and the length of the
            // longest subsequence end with an up position is the
            // length of down subsequence plus 1. 
            if(nums[i] > nums[i-1]) {
                up = down + 1;
            }
            // If the current element is smaller than its previous
            // element, it's on a down position. Then its previous
            // element must be a up position. 
            else if(nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }
        
        return max(up, down);
    }
};
