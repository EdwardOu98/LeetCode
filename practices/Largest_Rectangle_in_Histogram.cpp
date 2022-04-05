#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0, i = 0;
        heights.push_back(0);
        int n = heights.size();

        while(i < n) {
            // 如果栈空或当前柱子的高度比栈顶下标对应的柱子的高度更高，则将当前柱子的下标压入栈中
            if(stk.empty() || heights[i] >= heights[stk.top()]) {
                stk.push(i++);
            }
            // 如果栈不空且当前柱子的高度小于等于栈顶下标对应的柱子的高度，则将栈顶下标弹出并计算以
            // 被弹出下标所对应的柱子的高度为高的矩形的面积
            else {
                int j = stk.top();
                stk.pop();
                maxArea = max(maxArea, heights[j] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }

        return maxArea;
    }
};
