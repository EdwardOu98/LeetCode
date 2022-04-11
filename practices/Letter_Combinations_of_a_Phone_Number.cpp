#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    // An array that stores the letters corresponding to each number
    string umap[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Depth First Search
    void dfs(string& digits, string& temp, vector<string>& res, int idx) {
        // If the current index is exceeds the valid range, it means we had finished
        // with one combination and we can push the current array into the result
        if(idx >= digits.length()) {
            res.push_back(temp);
            return;
        }

        // For each character associated with each digit, we push them into temporary
        // string and go one level deeper. After returning from the lower level, we
        // remove the character we just added from the temporary string
        for(char& c : umap[digits[idx] - '2']) {
            temp.push_back(c);
            dfs(digits, temp, res, idx + 1);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string& digits) {
        if(digits.empty()) {
            return {};
        }
        vector<string> res;
        string temp;
        
        dfs(digits, temp, res, 0);
        
        return res;
    }
};
