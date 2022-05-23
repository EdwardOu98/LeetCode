#include <cctype>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    stack<int> nums;
    stack<char> ops;

    // Get the priority of the current operator
    int getPriority(char& op) {
        if(op == '+' || op == '-') {
            return -1;
        }
        return 1;
    }

    // Take the top 2 elements from the nums stack
    // and evaluate with the input operator
    void evaluate(char& op) {
        int right = nums.top();
        nums.pop();
        int left = nums.top();
        nums.pop();

        if(op == '+') {
            nums.push(left + right);
        }
        else if(op == '-') {
            nums.push(left - right);
        }
        else if(op == '*') {
            nums.push(left * right);
        }
        else {
            nums.push(left / right);
        }
    }
public:
    int calculate(string s) {
        int n = s.length();
        int i = 0;

        while(i < n) {
            // If the current character is a number, construct the operand
            if(isdigit(s[i])) {
                int num = 0;
                while(i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                nums.push(num);
            }
            // If the current character is a space, skip it
            else if(isspace(s[i])) {
                ++i;
            }
            // If the current character is an operator
            else {
                // If the current operator's priority is lower than or equal to the 
                // priority of the operator stack's top element, use the top operator
                // to evaluate the top two elements in the nums stack
                while(!ops.empty() && (getPriority(s[i]) <= getPriority(ops.top()))) {
                    evaluate(ops.top());
                    ops.pop();
                }
                ops.push(s[i]);
                ++i;
            }
        }

        // If the ops stack is not empty
        while(!ops.empty()) {
            evaluate(ops.top());
            ops.pop();
        }

        return nums.top();
    }
};
