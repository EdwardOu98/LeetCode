#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    int stackSolution(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        int l = n, r = 0;
        for(int i = 0; i < n; ++i) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                l = min(l, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()) {
            s.pop();
        }
        
        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                r = max(r, s.top());
                s.pop();
            }
            s,push(i);
        }
        return (r - l) < 0 ? 0 : r - l + 1;
    }
    
    int constantSpaceSolution(vector<int>& nums) {
        int minEle = INT_MAX, maxEle = INT_MIN;
        bool flag = false;
        for(int i = 1; i < n; ++i) {
            if(nums[i] < nums[i-1]) {
                flag = true;
            }
            if(flag) {
                minEle = min(minEle, nums[i]);
            }
        }
        
        flag = false;
        for(int i = n - 2; i >= 0; --i) {
            if(nums[i] > nums[i+1]) {
                flag = true;
            }
            if(flag) {
                maxEle = max(maxEle, nums[i]);
            }
        }
        
        int l, r;
        for(l = 0; l < n; ++l) {
            if(minEle < nums[l]) {
                break;
            }
        }
        
        for(r = n - 1; r >= 0; --r) {
            if(maxEle > nums[r]) {
                break;
            }
        }
        
        return (r - l) < 0 ? 0 : r - l + 1;
    }
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return 0;
        }
        int l = 0, r = n - 1;
        int ll = n, rr = 0; // ll - the left boundary of the unsorted region
                            // rr - the right boundary of the unsorted region
        
        // Find the left boundary of the unsorted region
        for(int i = 1; i < n; ++i) {
            // Use the left half of the input array as a stack and l is the 
            // stack top pointer. If the current number is greater than or
            // equal to the stack top element, move the stack top to the right. 
            if(nums[i] >= nums[l]) {
                ++l;
            }
            else {
                // Otherwise, we move the stack top to the left until
                // the stack top element is smaller than or equal to
                // the current element
                while(l >= 0 && nums[i] < nums[l]) {
                    ll = min(ll, l--);
                }
                // If the stack becomes empty after the calculation
                // (the current element is the minimum element in
                // the entire array), we leave the loop
                if(l < 0) {
                    break;
                }
            }
        }
        
        // Find the left boundary of the unsorted region
        for(int i = n - 2; i >= 0; --i) {
            // Use the right half of the input array as a stack and r is the 
            // stack top pointer. If the current number is less than or equal
            // to the stack top element, move the stack top to the left. 
            if(nums[i] <= nums[r]) {
                --r;
            }
            else {
                while(r < n && nums[i] > nums[r]) {
                    rr = max(rr, r++);
                }
                // If the stack becomes empty after the calculation
                // (the current element is the maximum element in
                // the entire array), we leave the loop
                if(r >= n) {
                    break;
                }
            }
        }

        return (rr - ll) < 0 ? 0 : rr - ll + 1;
    }
};
