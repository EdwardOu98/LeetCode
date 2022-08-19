#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        
        for(int& i : nums) {
            ++left[i];
        }
        
        for(int& i : nums) {
            // If the current number is already part of
            // a subsequence, continue to the next number
            if(left[i] == 0) {
                continue;
            }
            
            --left[i];
            
            // If the current number can be added to the 
            // end of an existing subsequence, add the
            // current number to the subsequence
            if(end[i-1] > 0) {
                --end[i-1];
                ++end[i];
            }
            // If it can't be added to an existing subsequence,
            // then we should consider a new subsequence starting
            // with the current number
            else if(left[i+1] > 0 && left[i+2] > 0) {
                --left[i+1];
                --left[i+2];
                ++end[i+2];
            }
            // If the number cannot be used to form a subsequence,
            // return false
            else {
                return false;
            }
        }
        
        return true;
    }
};
