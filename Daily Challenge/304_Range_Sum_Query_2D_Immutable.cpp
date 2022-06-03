#include <vector>

using namespace std;

class NumMatrix {
private:
    // PrefixSum[i][j] is the sum of element in the rectangle with
    // [0, 0] as its top left corner and [i, j] as its bottom right
    // corner
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        prefixSum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] + 
                                  matrix[i-1][j-1] - prefixSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum[row2+1][col2+1] - prefixSum[row1][col2+1] -
               prefixSum[row2+1][col1] + prefixSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
