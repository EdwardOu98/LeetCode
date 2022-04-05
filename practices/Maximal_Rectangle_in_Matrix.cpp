#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
// 思路：将矩阵转换成直方图，然后用求直方图最大矩形面积的方法求矩阵中最大矩形面积
private:
    int largestRectangleinHistogram(vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0, i = 0;
        heights.push_back(0);
        int n = heights.size();

        while(i < n) {
            if(stk.empty() || heights[i] >= heights[stk.top()]) {
                stk.push(i++);
            }
            else {
                int j = stk.top();
                stk.pop();
                maxArea = max(maxArea, heights[j] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }

        heights.pop_back();
        return maxArea;
    }
public:
    int maximalRectangle(vector<string>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(n, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // 如果矩阵当前元素为0，则将直方图对应的列元素置0
                if(matrix[i][j] == '0') {
                    heights[j] = 0;
                }
                // 否则将直方图对应的列元素加1
                else {
                    ++heights[j];
                }
            }
            maxArea = max(maxArea, largestRectangleinHistogram(heights));
        }

        return maxArea;
    }
};
