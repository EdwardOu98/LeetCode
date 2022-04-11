#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void dfs(int l, int r, vector<string>& res, string s) {
        // When both left and right parentheses are used up, 
        // push the current string into the result array
        if(l == 0 && r == 0) {
            res.push_back(s);
            return;
        }
        
        // If we still have more open parentheses, add one
        // to the end of the string and go down one level
        if(l > 0) {
            dfs(l - 1, r, res, s + "(");
        }
        // If we still have more open parentheses and we have
        // already added open parentheses into the string, we
        // can now add closing parentheses to the string and
        // go down one level
        if(r > 0 && l < r) {
            dfs(l, r-1, res, s + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        
        dfs(n, n, res, s);
        
        return res;
    }
};
