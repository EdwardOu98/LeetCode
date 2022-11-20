#include <string>
#include <stack>
#include <cctype>

using namespce std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<int> ops; 
        int res = 0;
        int num = 0, sign = 1;
        
        for(char c : s) {
            // If the current character is a digit, we
            // add it to the current operand.
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            // If we see an operator, we add the current
            // operand to the result and set the sign
            // accordingly
            else if(c == '+' || c == '-') {
                res += sign * num;
                num = 0; // Reset operand
                sign = (c == '+') ? 1 : -1;
            }
            // If we see an left parenthese, we push the 
            // current result and sign into their stacks
            // and reset the sign and result for calculation
            // inside the parentheses
            else if(c == '(') {
                nums.push(res);
                ops.push(sign);
                res = 0;
                sign = 1;
            }
            // If we see a right parenthese and the ops stack
            // is not empty, we first add the current number
            // to the result to handle cases such as 1 - (5). 
            // Then add the top element of the nums stack
            // to the result. 
            else if(c ==')' && !ops.empty()) {
                res += sign * num;
                num = 0;
                
                res = res * ops.top() + nums.top();
                ops.pop();
                nums.pop();
            }
        }
        
        // Add the final operand to the result
        return res += num * sign;
    }
};
