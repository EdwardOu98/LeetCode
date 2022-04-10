#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        
        for(string& op : ops) {
            if(op == "+") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.push(num1);
                stk.push(num1 + num2);
            }
            else if(op == "C") {
                stk.pop();
            }
            else if(op == "D") {
                stk.push(stk.top() * 2);
            }
            else {
                stk.push(stoi(op));
            }
        }
        
        int res = 0;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        
        return res;
    }
};
