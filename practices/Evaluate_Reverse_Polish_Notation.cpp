#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums; // 用于保存操作数
        int res = 0;
        for(string& s : tokens) {
            // 如果当前串是运算符，则从栈顶弹出两个操作数(注意先弹出的为右操作数，后弹出的为左操作数)
            // 进行运算，然后将结果压入栈中
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                switch(s[0]) {
                    case '+':
                        nums.push(left + right);
                        break;
                    case '-':
                        nums.push(left - right);
                        break;
                    case '*':
                        nums.push(left * right);
                        break;
                    default:
                        nums.push(left / right);
                }
            }
            // 如果当前字符串是数字，则直接入栈
            else {
                nums.push(stoi(s));
            }
        }

        return nums.top();
    }
};
