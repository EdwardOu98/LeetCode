#include <string>
#include <cstring>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // If the dictionary is empty, return false
        if(wordDict.empty()) {
            return false;
        }
        unordered_set<string> dict;
        int maxLen = 0;
        
        // Put the words into a set, and record the maximum
        // length of the words
        for(string& word: wordDict) {
            maxLen = max(maxLen, (int) word.length());
            dict.insert(word);
        }
        
        int n = s.length();
        bool dp[n + 1]; // dp[i] is whether we could break the string
                        // into words in the dictionary up to index i-1
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = i - 1; j >= max(i - maxLen, 0); --j) {
                // starting from the last position where we 
                // successfully break to string into words, 
                // we check whether the substring from j to i
                // is a word in dictionary. If it is, set dp[i]
                // to true.
                if(dp[j]) {
                    string str = s.substr(j, i - j);
                    if(dict.count(str)) {
                        dp[i] = true;
                    }
                }
            }
        }
        
        return dp[n];
    }
};
