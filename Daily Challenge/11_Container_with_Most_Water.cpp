#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;   // Left and right boundary of the container
        int res = 0;                        // Maximum amount of water can be stored
        int w, h;                           // Width and height of the container
        
        while(l < r) {
            w = r - l;                      // Width equals r - l
            if(height[l] > height[r]) {     // Height is the shorter verticle line between
                h = height[r];              // the left and the right one
                --r;
            }
            else {
                h = height[l];
                ++l;
            }
            
            res = max(res, w * h);          // Update result
        }
        
        return res;
    }
};
