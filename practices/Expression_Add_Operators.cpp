#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> res;
    int n; // Number of digits
    string num;
    int target;
    
    // Inputs: num - the input number
    //         curr - the expression's result up to the current point
    //         prev - the previous operand
    //         target - the target value we are trying to get
    //         exp - the expression up to the current index
    //         idx - the current index we are on
    //         op - the last operator we inserted
    void dfs(long curr, long prev, string exp, int idx, char op) {
        // If we reach the end of the input number and the current sum is equal to the target,
        // add the current expression into the result array
        if(idx >= n) {
            if(curr == target){
                res.push_back(exp);
            }
            return;
        }
        
        for(int i = idx + 1; i <= n; ++i) {
            // Get the new operand
            string str = num.substr(idx, i - idx);
            long operand = stol(str);
            // If we have a leading 0, exit the loop
            if(to_string(operand).length() != str.length()) {
                break;
            }
            // Try to add a '+' before the current operand. 
            dfs(curr + operand, operand, exp + "+" + str, i, '+');
            // Try to add a '-' before the current operand
            dfs(curr - operand, operand, exp + "-" + str, i, '-');
            // To add a '*' before the current operand, we might need to re-evaluate
            // the current expression because '*' has higher priority than '+' and '-'.
            // If the last operator we inserted was '+':
            if(op == '+') {
                dfs(curr - prev + prev * operand, prev * operand, exp + "*" + str, i, op);
            }
            // If the last operator inserted was '-':
            else if(op == '-') {
                dfs(curr + prev - prev * operand, prev * operand, exp + "*" + str, i, op);
            }
            // If the last operator inserted was '*':
            else {
                dfs(curr * operand, prev * operand, exp + "*" + str, i, op);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        
        n = num.length();
        for(int i = 1; i <= n; ++i) {
            string str = num.substr(0, i);
            long operand = stol(str);
            if(to_string(operand).length() != str.length()) {
                continue;
            }
            // For the first operand in the expression, both the current and 
            // prev value are the operand itself. And for simplicity, we set
            // the initial operator as '*'
            dfs(operand, operand, str, i, '*');
        }
        
        return res;
    }
};
