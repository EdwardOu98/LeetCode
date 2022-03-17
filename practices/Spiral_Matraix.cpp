#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return {};
        }
        // 记录矩阵的大小
        int m = matrix.size(), n = matrix[0].size();
        // 记录四个移动方向
        vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // 记录每个方向当前最多能移动几步，下标0为水平方向，下标1为垂直方向
        vector<int> steps{n, m - 1};
        // 结果
        vector<int> res;
        // 当前方向从0开始
        int currDir = 0;
        int r = 0, c = -1;
        
        // 当currDir为0或2时，我们在水平方向上扫描矩阵，而currDir%2为0，对应水平方向上能移动的步数
        // 当currDir为1或3时，我们在垂直方向上扫描矩阵，而currDir%2为1，对应垂直方向上能移动的步数
        while(steps[currDir % 2]) {
            for(int i = 0; i < steps[currDir % 2]; ++i) {
                r += directions[currDir][0];
                c += directions[currDir][1];
                res.push_back(matrix[r][c]);
            }
            // 每当扫描完一个方向后，下次再扫描这个方向时会比这一次少一个，因为在下一个循环中方向会变为
            // 垂直方向，并扫描当前所在列。如果步数保持不变，会导致下标超出给定范围。所以需要将步数减1
            --steps[currDir % 2];
            currDir = (currDir + 1) % 4;
        }
        

        return res;
    }
};
