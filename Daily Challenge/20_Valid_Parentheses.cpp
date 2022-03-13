#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(char c : s) {
            switch(c) {
                case '(' :
                    stk.push(')');
                    break;
                case '[' :
                    stk.push(']');
                    break;
                case '{' :
                    stk.push('}');
                    break;
                case ')' :
                case ']' :
                case '}' :
                    if(stk.empty() || stk.top() != c) {
                        return false;
                    }
                    stk.pop();
            }
        }
        
        return stk.empty();
    }
};
