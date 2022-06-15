#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool comp(string& a, string& b) {
        return a.length() < b.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        // Sort the words on their length
        sort(words.begin(), words.end(), comp);
        
        int res = 0; // The maximum length of word chain
        unordered_map<string, int> dp; // word - maximum chain length with this word
        
        for(string& w : words) {
            // For each word, we try to delete one of its character and see if we can
            // find any predecessor. If there's no predecessor, the chain length is 1.
            // Otherwise, the chain length should be the longest chain length +1.
            for(int i = 0; i < w.length(); ++i) {
                string pred = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.count(pred) ? dp[pred] + 1 : 1);
            }
            
            // Update the maximum length
            res = max(res, dp[w]);
        }
        
        return res;
    }
};
