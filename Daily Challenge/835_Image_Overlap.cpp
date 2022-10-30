#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n;
    
    int countOverlaps(vector<vector<int>>& a, vector<vector<int>>& bShift, int xShift, int yShift) {
        int res = 0;
        
        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                res += a[row][col] * bShift[row + yShift][col + xShift];
            }
        }
        
        return res;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        vector<vector<int>> bShift(3 * n - 2, vector<int>(3 * n - 2, 0));
        
        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                bShift[row + n - 1][col + n - 1] = img2[row][col];
            }
        }
        
        int maxOverlaps = 0;
        
        for(int xShift = 0; xShift < 2 * n - 1; ++xShift) {
            for(int yShift = 0; yShift < 2 * n - 1; ++yShift) {
                maxOverlaps = max(maxOverlaps, countOverlaps(img1, bShift, xShift, yShift));
            }
        }
        
        return maxOverlaps;
    }
};
