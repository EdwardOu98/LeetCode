#include <deque>
#include <set>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> res;
    int n;
    
    void multisetSolution(vector<int>& nums, int k) {
        multiset<int> mset;
        
        for(int i = 0; i < n; ++i) {
            mset.insert(nums[i]);
            if(mset.size() == k) {
                res.push_back(*mset.rbegin());
                mset.erase(mset.find(nums[i - k + 1]));
            }
        }
        
    }
    
    void dequeSolution(vector<int>& nums, int k) {
        deque<int> dq;
        
        for(int i = 0; i < n; ++i) {
            // If the deque is not empty and the current number
            // is greater than or equal to the number indicated
            // by the last element of the deque, remove the last
            // element of the deque
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            // Add the current index to the deque
            dq.push_back(i);
            
            // If we have gone through at least one window, add
            // the maximum in the current window (which is 
            // indicated by the first element in the deque)
            // to the result array
            if(i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
            
            // If the first element is at the left boundary of
            // the window, remove it from the deque
            if(dq.front() <= i - k + 1) {
                dq.pop_front();
            }
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        n = nums.size();
        // multisetSolution(nums, k);
        dequeSolution(nums, k);
        return res;
    }
};
