#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // If the input array is empty, return 0
        if(height.empty()) {
            return 0;
        }

        int res = 0; // Result
        int lmax = 0; // The maximum height on the left
        int rmax = 0; // The maximum height on the right
        int l = 0, r = height.size() - 1;

        while(l <= r) {
            if(height[l] < height[r]) {
                // If the current height on the left side is higher than
                // the previous maximum height, update the maximum height.
                // Otherwise, update the amount of water that can be trapped. 
                if(height[l] > lmax) {
                    lmax = height[l];
                }
                else {
                    res += lmax - height[l];
                }
                ++l;
            }
            else {
                // If the current height on the right side is higher than
                // the previous maximum height, update the maximum height.
                // Otherwise, update the amount of water that can be trapped. 
                if(height[r] > rmax) {
                    rmax = height[r];
                }
                else {
                    res += rmax - height[r];
                }
                --r;
            }
        }

        return res;
    }
};
