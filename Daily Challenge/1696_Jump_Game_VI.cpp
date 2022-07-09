#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int res = 0;
        
        deque<int> dq; // Stores the indices of maximum element in the
                       // sliding window
        
        for(int i = nums.size() - 1; i >= 0; --i) {
            // Get the current maximum sum
            res = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);
            
            // Remove all elements smaller than the current maximum
            // from the queue
            while(!dq.empty() && res > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            // If the current largest element in the queue is out of bound,
            // remove it from the queue
            if(dq.front() >= i + k) {
                dq.pop_front();
            }
            
            // Use the input array to store the temporary result
            nums[i] = res;
        }
        
        return res;
    }
};
