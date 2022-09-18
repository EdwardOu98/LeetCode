#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) {
            return 0;
        }
        
        int res = 0, lmax = 0, rmax = 0, l = 0, r = height.size() - 1;
        
        while(l <= r) {
            if(height[l] < height[r]) {
                if(height[l] > lmax) {
                    lmax = height[l];
                }
                else {
                    res += lmax - height[l];
                }
                ++l;
            }
            else {
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
