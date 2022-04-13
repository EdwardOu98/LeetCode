#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int steps[2] = {n, n - 1};
        int num = 1, r = 0, c = -1, currDir = 0, i;
        
        
        while(steps[currDir % 2]) {
            for(i = 0; i < steps[currDir % 2]; ++i) {
                r += directions[currDir][0];
                c += directions[currDir][1];
                res[r][c] = num++;
            }
            --steps[currDir % 2];
            currDir = (currDir + 1) % 4;
        }
        
        return res;
    }
};
