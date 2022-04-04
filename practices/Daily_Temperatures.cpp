#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> stk; // 用于保存数组元素的下标

        // 遍历温度数组
        for(int currDay = 0; currDay < n; ++currDay) {
            int currTemperature = temperatures[currDay];

            // 如果栈不空且栈顶日期对应的温度小于当前温度，则更新结果数组中栈顶日期对应
            // 的天数并将栈顶日期弹出
            while(!stk.empty() && temperatures[stk.top()] < currTemperature) {
                res[stk.top()] = currDay - stk.top();
                stk.pop();
            }

            // 将当前日期压入栈中
            stk.push(currDay);
        }

        return res;
    }
};
