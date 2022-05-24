#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // If the input string is empty, return 0
        if(s.empty()) {
            return 0;
        }
        
        int res = 0, n = s.length();
        stack<int> stk; // Stores the indices of the left parentheses
        stk.push(-1);
        
        for(int i = 0; i < n; ++i) {
            // If we see a left parenthesis, add its index to the stack
            if(s[i] == '(') {
                stk.push(i);
            }
            // If we see a right parenthesis
            else {
                // Remove the top element from the stack
                stk.pop();
                // If the stack becomes empty, it means the current right parenthesis
                // is an extra. We need to add its index to the stack.
                if(stk.empty()) {
                    stk.push(i);
                }
                // If the stack is not empty, then the range (stk.top(), i] is the longest
                // valid parenthesis. 
                else {
                    res = max(res, i - stk.top());
                }
            }
        }
        
        return res;
    }
};
