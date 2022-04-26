#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<int>> memo;
    
    vector<int> DPwithMemo(string expression) {
        vector<int> res; // The result array of the current level
        int n = expression.length();
        for(int i = 0; i < n; ++i) {
            // If the current character is an operator, it's possible
            // to be used as the last operater in the process of 
            // evaluation. 
            if(!isdigit(expression[i])) {
                vector<int> res1, res2;
                // Evaluate the expression consisted of the first i
                // characters
                string str = expression.substr(0, i);
                // If the result has been calculated before, use the
                // memoized result;
                if(memo.count(str)) {
                    res1 = memo[str];
                }
                else {
                    res1 = DPwithMemo(str);
                }
                
                // Evaluate the expression consisted of the rest of
                // expression
                str = expression.substr(i + 1);
                // If the result has been calculated before, use the
                // memoized result;
                if(memo.count(str)) {
                    res2 = memo[str];
                }
                else {
                    res2 = DPwithMemo(str);
                }
                
                // After we obtain the two evaluation results, we
                // calculate all possible combinations
                for(int num1 : res1) {
                    for(int num2 : res2) {
                        if(expression[i] == '+') {
                            res.push_back(num1 + num2);
                        }
                        else if(expression[i] == '-') {
                            res.push_back(num1 - num2);
                        }
                        else {
                            res.push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        
        // After we go through the entire string, if the result
        // array is still empty, it means that the input expression
        // is completely consisted of numbers. Thus, we convert it
        // to a number and add it to the result array;
        if(res.empty()) {
            res.push_back(stoi(expression));
        }
        
        return memo[expression] = res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return DPwithMemo(expression);
    }
};
