#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n - 1;
        
        // Start searching at the top-right corner of the matrix
        while(r < m && c >= 0) {
            if(matrix[r][c] == target) {
                return true;
            }
            // If the current element is too large, we move to
            // the left
            else if(matrix[r][c] > target) {
                --c;
            }
            // If the current element is too small, we move down
            else {
                ++r;
            }
        }
        
        return false;
    }
};
