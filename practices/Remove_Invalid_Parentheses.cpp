#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_set<string> res; // Stores the result and get rid of duplicates
    string s;
    int n;
    
    /* Inputs: 
     * - idx: the current index we are on
     * - removed_left: the number of left parentheses we need to remove
     * - removed_right: the number of right parentheses we need to remove
     * - pairs: when the value is not 0, we need to add right parentheses to make full pairs of parentheses
     * - exp: the current expression
     */
    void dfs(int idx, int removed_left, int removed_right, int pairs, string exp) {
        // If we reach the end of the string, check whether the current expression is valid.
        // If it's valid, add it to the result set. Otherwise, just return to the previous level
        if(idx == n) {
            if(removed_left == 0 && removed_right == 0 && pairs == 0) {
                res.insert(exp);
            }
            return;
        }
        
        // If the current character in the input string is a left parenthesis
        if(s[idx] == '(') {
            // If we need to remove the left parenthesis
            if(removed_left > 0) {
                dfs(idx + 1, removed_left - 1, removed_right, pairs, exp);
            }
            // If we keep the current left parenthesis
            dfs(idx + 1, removed_left, removed_right, pairs + 1, exp + s[idx]);
        }
        // If the current character in the input string is a right parenthesis
        else if(s[idx] == ')') {
            // If we need to remove the right parenthesis
            if(removed_right > 0) {
                dfs(idx + 1, removed_left, removed_right - 1, pairs, exp);
            }
            // We keep the current right parenthesis only when there is a left
            // parenthesis waiting for a right parenthesis to match with it
            if(pairs > 0) {
                dfs(idx + 1, removed_left, removed_right, pairs - 1, exp + s[idx]);
            }
        }
        // If the current character in the input string is any other character
        else {
            dfs(idx + 1, removed_left, removed_right, pairs, exp + s[idx]);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        n = s.length();
        int extra_left = 0, extra_right = 0;
        
        for(char c : s) {
            // If the current character is a left parenthesis, increment extra_left
            if(c == '(') {
                ++extra_left;
            }
            // If the current character is a right pareenthesis
            else if(c == ')') {
                // If extra_left > 0, it means that the current right parenthesis can match with
                // a left parenthesis to create a valid pair and eliminate one extra left parenthesis.
                // Otherwise, it's an extra right parenthesis
                if(extra_left > 0) {
                    --extra_left;
                }
                else {
                    ++extra_right;
                }
            }
        }
        
        dfs(0, extra_left, extra_right, 0, "");
        
        return vector<string>(res.begin(), res.end());
    }
};
