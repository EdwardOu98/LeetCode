#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long MOD = 1e9+7;
        
        stack<int> s;
        long sum = 0;
        int n = arr.size();
        
        // Build the monotonically increasing stack
        for(int i = 0; i <= n; ++i) {
            // When i reaches the array length, it is an indication that
            // all the elements have been processed, and the remaining 
            // elements in the stack should be popped out.
            
            // The >= in the loop condition ensures the same number 
            // won't be considered twice. 
            while(!s.empty() && (i == n || arr[s.top()] >= arr[i])) {
                int mid = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                int right = i;
                
                long count = (mid - left) * (right - mid) % MOD;
                
                sum += (count * arr[mid]) % MOD;
                sum %= MOD;
            }
            
            s.push(i);
        }
        
        return (int) sum;
    }
};
