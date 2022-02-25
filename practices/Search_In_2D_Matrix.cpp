#include <vector>

using namespace std;

class Solution {
// 思路：从2维数组的右上角开始遍历数组。
// 如果当前数字小于目标，则向下移动一行；
// 如果当前数字大于目标，则向左移动一列。
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();

        int i = 0, j = n - 1;

        while(i < m && j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            }
            else if(target > matrix[i][j]) {
                ++i;
            }
            else {
                --j;
            }
        }

        return false;
    }
};
