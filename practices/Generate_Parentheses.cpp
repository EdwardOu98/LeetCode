#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> res;

    void dfs(int left, int right, string s) {
        // If both the left and right parentheses are used up,
        // push the string into the result array and return to
        // the previous level
        if(left == 0 && right == 0) {
            res.push_back(s);
            return;
        }

        // If there are left parentheses left, add it to the string
        // and go down one level
        if(left > 0) {
            dfs(left - 1, right, s + "(");
        }

        // If there are right parentheses left and the number of unsed
        // right parentheses is more than the number of unsed left 
        // parentheses, which means we currently have more left parentheses
        // in the string, we add a right parenthese into the string and go
        // down one level
        if(right > 0 && right > left) {
            dfs(left, right - 1, s + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");

        return res;
    }
};
