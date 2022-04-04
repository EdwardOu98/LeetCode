#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(int& asteroid : asteroids) {
            // 当栈顶元素为正且其绝对值小于当前负数的绝对值，则将栈顶元素出栈直到
            // 栈空或栈顶元素大于等于当前负数的绝对值
            while(!stk.empty() && stk.top() > 0 && stk.top() < -asteroid) {
                stk.pop();
            }
            // 当栈顶元素为正且其绝对值与当负前数的绝对值，则将栈顶元素出栈
            if(!stk.empty() && asteroid < 0 && stk.top() == -asteroid) {
                stk.pop();
            }
            // 仅当栈空、当前元素为正、或栈顶元素为负时才将当前元素压入栈中
            else if(asteroid > 0 || stk.empty() || stk.top() < 0){
                stk.push(asteroid);
            }
        }

        vector<int> res;
        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
