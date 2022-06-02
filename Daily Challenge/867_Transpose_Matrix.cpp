#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        
        vector<vector<int>> res(n, vector<int>(m));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res[j][i] = matrix[i][j];
            }
        }
        
        return res;
    }
};
