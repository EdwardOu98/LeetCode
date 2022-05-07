#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int num = INT_MIN; // The second largest element in the 132 pattern
        stack<int> s; // stores the largest element in the 132 pattern
        
        for(int i = nums.size() - 1; i >= 0; --i) {
            // If the current element is smaller than num, which is the second largest
            // element in the 132 pattern, that means we have found the pattern in the
            // array. Return true
            if(nums[i] < num) {
                return true;
            }
            
            // If the current element is larger than the top element in the stack, 
            // then we need to update the second largest element and remove it from
            // the stack
            while(!s.empty() && nums[i] > s.top()) {
                num = s.top();
                s.pop();
            }
            
            // Add the current element into the stack
            s.push(nums[i]);
        }
        
        // If we didn't find the pattern in the string, return false
        return false;
    }
};
