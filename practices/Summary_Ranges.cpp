#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int beg, end;
        
        for(int i = 0; i < n; ++i) {
            // Record the beginning of the range
            beg = nums[i];
            // Find the end of the range, which satisfy the
            // condition that nums[i] + 1 != nums[i+1]
            while(i < n - 1 && nums[i] + 1 == nums[i+1]) {
                ++i;
            }
            // Record the end of the range
            end = nums[i];
            
            // If the beginning and the end are the same, 
            // that means we have only one element for the
            // current range. Just add it to the result array
            if(beg == end) {
                res.push_back(to_string(beg));
            }
            // If they are not the same, construct a string
            // with the format specified by the problem and 
            // add it to the result array
            else {
                res.push_back(to_string(beg) + "->" + to_string(end));
            }
        }
        
        return res;
    }
};
