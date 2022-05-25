#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isEqual(const string& s, int start, int end, const string& word) {
        // If the part we try to check in the sentence doesn't exist or
        // the part's length is not the same as the word, return false
        if(end - start < 0 || end - start != word.length()) {
            return false;
        }

        for(int i = 0; start < end; ++start, ++i) {
            if(s[start] != word[i]) {
                return false;
            }
        }

        return true;
    }
public:
    int respace(vector<string>& dictionary, string sentence) {
        const int len = sentence.length();
        int dp[len+1];
        dp[0] = 0;
        for(int i = 1; i <= len; ++i) {
            dp[i] = dp[i-1] + 1;
            // For each substring length, try to find a substring that matches the best 
            // with the words in the dictionary
            for(const string& word : dictionary) {
                if(word.size() <= i && isEqual(sentence, i - word.size(), i, word)) {
                    dp[i] = min(dp[i], dp[i - word.size()]);
                }
            }
        }

        return dp[len];
    }
};
