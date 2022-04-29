#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefixSum; // Stores the prefix sum from the top-left
                                   // corner of the matrix to the current element
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefixSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                // The prefix sum of the current element is the sum from (0, 0)
                // to the element directly above the current element (which is
                // prefixSum[i-1][j]) plus the prefix sum from (0, 0) to the element
                // on the left side of the current element (which is prefixSum[i][j-1])
                // plus the current element. But because the prefix sum to the top-left
                // element of the current one is counted twice in the calculation, we
                // need subtract one of this part from the result
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] 
                                + matrix[i-1][j-1] - prefixSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // The sum from (row1, col1) to (row2, col2) is the prefix sum until (row2, col2)
        // minus the prefix sum to the left of col1 (which is prefixSum[row2+1][col1]),
        // and minus the prefix sum to the top of row1 (which is prefixSum[row1][col2+1]).
        // But because the area from the top-left of the matrix to (row1-1, col1-1) is
        // subtracted from the result twice, we need to add this part back to the result.
        return prefixSum[row2+1][col2+1] - prefixSum[row2+1][col1] 
                - prefixSum[row1][col2+1] + prefixSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
