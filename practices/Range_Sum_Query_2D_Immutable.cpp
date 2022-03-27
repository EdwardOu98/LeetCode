#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sums; // 用于存储当前元素的前缀和
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sums = vector<vector<int>>(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                // 当前元素的前缀和等于这一行的前缀和加这一列的前缀和加元素本身减去左上角元素的前缀和
                sums[i][j] = matrix[i-1][j-1] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
