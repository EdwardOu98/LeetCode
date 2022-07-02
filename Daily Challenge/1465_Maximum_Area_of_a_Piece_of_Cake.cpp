#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Idea: Sort the two arrays, find the maximum gap between the cuts, and multiply 
    // the gaps together to get the final result
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // Sort the two input arrays
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int m = horizontalCuts.size() - 1, n = verticalCuts.size() - 1;
        
        int max_h = max(horizontalCuts[0], h - horizontalCuts[m]);
        int max_w = max(verticalCuts[0], w - verticalCuts[n]);
        
        for(int i = 0; i < m; ++i) {
            max_h = max(max_h, horizontalCuts[i+1] - horizontalCuts[i]);
        }
        
        for(int i = 0; i < n; ++i) {
            max_w = max(max_w, verticalCuts[i+1] - verticalCuts[i]);
        }
        
        return ((long) max_h * max_w) % (1000000007);
    }
};
