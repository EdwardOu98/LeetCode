#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> dict; // reversed word - index
        vector<vector<int>> res;
        
        // Build the dictionary
        for(int i = 0; i < n; ++i) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        
        // Edge case: Empty string. If an empty string exists, we first find
        // all palindormes in the original input array and use them for the
        // case of "" + word
        if(dict.count("")) {
            for(int i = 0; i < n; ++i) {
                // If the current string is the empty string, we skip it
                if(i == dict[""]) {
                    continue;
                }
                // If the current string is palindormic, add it to the result
                // array
                if(isPalindrome(words[i])) {
                    res.push_back({dict[""], i});
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            int len = words[i].length();
            for(int j = 0; j < len; ++j) {
                // Separate the string into 2 parts
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, len - j);
                
                // If we are able to find the left part in the dictionary, 
                // the right part is a palindrome itself, and the left part
                // is not the current string itself, then we can form a
                // palindrome with the current word and the left part
                if(dict.count(left) && isPalindrome(right) && i != dict[left]) {
                    res.push_back({i, dict[left]});
                }
                
                // If we are able to find the right part in the dictionary,
                // the left part is a palindrome itself, and the right part
                // is not the current word itself, then we can form a 
                // palindrome with the right part and the current word
                if(dict.count(right) && isPalindrome(left) && i != dict[right]) {
                    res.push_back({dict[right], i});
                }
            }
        }
        
        return res;
    }
};
