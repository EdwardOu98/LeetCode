#include <stack>
#include <string>

using namespace std;

class Solution {
private:
    stack<int> nums; // stores intermediate results
    stack<char> ops; // stores operators
    int left;
    int right;
    
    // Get the priority of the operator. If the 
    // operator is '+' or '-', the its priority
    // is -1. Otherwise it's 1. 
    int getPriority(char op) {
        return op == '+' || op == '-' ? -1 : 1;
    }
    
    void getTwoNumbers() {
        right = nums.top();
        nums.pop();
        left = nums.top();
        nums.pop();
    }
    
    int calculate(char& op) {
        getTwoNumbers();
        if(op == '+') {
            return left + right;
        }
        if(op == '-') {
            return left - right;
        }
        if(op == '*') {
            return left * right;
        }
        
        return left / right;
    }
public:
    int calculate(string s) {
        if(s.empty()) {
            return 0;
        }
        int n = s.length();
        int num = 0, res;
        int i = 0;
        while(i < n) {
            // If we see a number, add it to the nums stack
            if(isdigit(s[i])) {
                while(i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                nums.push(num);
                num = 0;
            }
            // If we see a operator, follow the rules below:
            // - If the ops stack is empty or the current operator's
            //   priority is higher than that of the top element in the
            //   ops stack, directly add it to the ops stack;
            // - If the ops stack is not empty and the priority of the
            //   current operator is lower than or equal to that of
            //   the top element in the ops stack, take two numbers
            //   from the nums stack and the top operator in the ops stack
            //   and calculate the result, then add the result back to the
            //   nums stack. Continue until the first condition is met. 
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                while(!ops.empty() && getPriority(s[i]) <= getPriority(ops.top())) {
                    res = calculate(ops.top());
                    ops.pop();
                    nums.push(res);
                }
                ops.push(s[i]);
                ++i;
            }
            // If the current character is a space, continue the loop without doing anything
            else {
                ++i;
            }
        }
        
        // If we reached the end of the string and the ops stack is still not
        // empty, do calculations until the ops stack becomes empty
        while(!ops.empty()) {
            res = calculate(ops.top());
            ops.pop();
            nums.push(res);
        }
        
        return nums.top();
    }
};
