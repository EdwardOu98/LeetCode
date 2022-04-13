#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Idea: Since the value of the input array represents a
    // jump range instead of the absolute jump length, we can
    // simply iterate through the array and record the largest
    // index we can reach. 
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), curr = -1, next = 0, steps = 0;
        for(int i = 0; next < n - 1; ++i) {
            if(i > curr) {
                ++steps;
                curr = next;
            }
            
            next = max(next, i + nums[i]);
        }
        
        return steps;
    }
};
