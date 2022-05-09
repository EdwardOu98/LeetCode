#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n; // length of input string
    vector<string> res; // Result array
    string temp; // Temporary string used to store the intermediate results
    
    void dfs(string& digits, int idx) {
        // If we reach the end of the input string, add the temp string
        // to the result array and return to the previous level
        if(idx >= n) {
            res.push_back(temp);
            return;
        }
        
        // Pick a character corresponding to the current digit and add
        // it to the temp string, then go down one level
        for(char& c : map[digits[idx] - '2']){
            temp.push_back(c);
            dfs(digits, idx + 1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string& digits) {
        n = digits.length();
        // If the input is not empty, use dfs to find all
        // possible combinations
        if(n) {
            dfs(digits, 0);
        }
        
        return res;
    }
};
