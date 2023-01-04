#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        int i, j = 0, k, m = pattern.length(), n = s.length();
        
        for(i = 0; i < n; i = k + 1) {
            // If we are at the end of the pattern string and
            // there are still words to process, return false
            if(j == m) {
                return false;
            }
            
            // Get a word from the input string
            k = i;
            while(k < n && s[k] != ' ') {
                ++k;
            }
            string word = s.substr(i, k - i);
            
            if(m1[pattern[j]] != m2[word]) {
                return false;
            }
            
            m1[pattern[j]] = m2[word] = j + 1;
            ++j;
        }
        
        return j == m;
    }
};
