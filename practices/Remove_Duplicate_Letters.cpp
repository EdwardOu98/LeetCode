#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counter[26] = {0}; // Record the characters' number of occurrences 
        bool visited[26] = {false}; // Record whether we have visited this character
                                    // before
        for(char& c : s) {
            ++counter[c - 'a'];
        }
        
        string res;
        
        for(char& c : s) {
            // Decrement the character count
            --counter[c - 'a'];
            
            // If the current character has been included in the result string,
            // we move on to the next character
            if(visited[c - 'a']) {
                continue;
            }
            
            // If the result string is not empty, we compare the current character
            // with the last character in the result string. If the current character
            // is smaller in lexicographical order and thee last character of the result
            // string still exist in the remaining part of the input string, we remove
            // the last character of the result string.
            while(!res.empty() && c < res.back() && counter[res.back() - 'a']) {
                // We need to reset the visited array for the removed character so that
                // we can make sure all characters in the original string are included
                // in the result string at the end
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            
            // Add the current character to the end of the result string
            res.push_back(c);
            visited[c - 'a'] = true;
        }
        
        return res;
    }
};
