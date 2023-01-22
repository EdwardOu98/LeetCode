#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> temp;
    int N;
    
    // Check whether a substring is palindromic
    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }
        
        return true;
    }
    
    void dfs(string& s, int idx) {
        // When we reach the end of the string, we push
        // the temp array into the result array
        if(idx >= N) {
            res.push_back(temp);
            return;
        }
        
        // First check whether a substring is palindromic.
        // If it is, add it to the temp array and go down
        // one level;
        for(int end = idx; end < N; ++end) {
            if(isPalindrome(s, idx, end)) {
                temp.push_back(s.substr(idx, end - idx + 1));
                dfs(s, end + 1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        N = s.length();
        
        dfs(s, 0);
        
        return res;
    }
};
