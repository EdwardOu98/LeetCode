#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i, j, r = -1;   // i, j, x, y - loop variables
                            // r - the last row that contains a 0
        
        // Find the last row that has a zero
        for(i = m - 1; i >= 0 && r == -1; --i) {
            for(j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    r = i;
                    break;
                }
            }
        }

        // If after the loops r is still zero, that means
        // the matrix doesn't have any zeros in it. Thus,
        // we leave the function
        if(r == -1) {
            return;
        }
        
        // Now we have the row index with the last 0 in the matrix
        // we will use this row to keep track of which columns have
        // zeros. We go down the matrix row by row until r. If we 
        // found a zero in that row, we mark the same column in r
        // as 0. 
        bool hasZero;   // This is the flag to record whether a zero
                        // exists in a row
        for(i = 0; i < r; ++i) {
            hasZero = false;
            for(j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    hasZero = true;
                    matrix[r][j] = 0;
                }
            }
            
            // If this row contains at least 1 zero, we set the entire row
            // to zero
            if(hasZero) {
                for(j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Then we use the information stored in r to set the columns as zero
        // and also set the non-zero elements in r to 0
        for(j = 0; j < n; ++j) {
            if(matrix[r][j] == 0) {
                for(i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
            matrix[r][j] = 0;
        }
        
        
    }
};
