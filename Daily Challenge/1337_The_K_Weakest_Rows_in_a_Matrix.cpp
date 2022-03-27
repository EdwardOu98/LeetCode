#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool compare(vector<int>& a, vector<int>& b) {
        // a[0] is the row index and a[1] is the number of soldiers
        // in the row
        return (a[1] < b[1]) || ((a[1] == b[1]) && (a[0] < b[0]));
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size(); // Record dimension of the matrix
        vector<vector<int>> counters(m, vector<int>(2, 0)); // Use an m x 2 matrix to store row index 
                                                            // and soldier counts
        int soldierCount, i, j;
        vector<int> res;
        for(i = 0; i < m; ++i) {
            soldierCount = 0;
            j = 0;
            // Count the number of soldiers in each row
            while(j < n && mat[i][j]) {
                ++soldierCount;
                ++j;
            }
            counters[i][0] = i;
            counters[i][1] = soldierCount;
        }
        
        sort(counters.begin(), counters.end(), compare);
        
        for(i = 0; i < k; ++i) {
            res.push_back(counters[i][0]);
        }
        
        return res;
    }
};
