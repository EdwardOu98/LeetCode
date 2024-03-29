#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    stack<long> s;
    long left, right;
    
    // Extract two numbers from the stack, note that
    // the first one extracted is the right operand
    void getTwoNumbers() {
        right = s.top();
        s.pop();
        left = s.top();
        s.pop();
    }
    
    long calculate(string& OP) {
        getTwoNumbers();
        switch(OP[0]) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
        }
        return left / right;
    }
public:
    int evalRPN(vector<string>& tokens) {
        
        for(string& token : tokens) {
            // If the current token is a number, push it
            // into the stack
            if(isdigit(token.back())) {
                s.push(stol(token));
            }
            // Otherwise, take two numbers from the top
            // of the stack and perform the operation
            // indicated by the token
            else {
                s.push(calculate(token));
            }
        }
        
        return s.top();
    }
};
