#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> memo; // To speed up the search by 
                                                // avoiding repetitive calculations
    vector<string> wordBreak(string s) {
        // If the result has been calculated before, return the memoized result
        if(memo.count(s)) {
            return memo[s];
        }
        
        vector<string> res;
        
        // If the input string exists in the dictionary, add it to the result array
        if(dict.count(s)) {
            res.push_back(s);
        }
        
        int n = s.length();
        
        for(int i = 1; i < n; ++i) {
            // Separate the input string into two substrings, one from index 0 to i-1;
            // The other from i to the end of the string. Firts check whether the second
            // part is a word in dictionary. If yes, then we try to break the first part
            // into words in dictionary and add the second part to the back of each 
            // breaking sequence. 
            string substr1 = s.substr(i);
            if(dict.count(substr1)) {
                string substr2 = s.substr(0, i);
                vector<string> prev = combine(substr1, wordBreak(substr2));
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        
        return memo[s] = res;
    }
    
    // Add s to the end of each string in res
    vector<string> combine(string& s, vector<string> res) {
        for(string& str : res) {
            str += " " + s;
        }
        
        return res;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string word: wordDict) {
            dict.insert(word);
        }
        
        return wordBreak(s);
    }
};
