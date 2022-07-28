#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if(t.length() != n) {
            return false;
        }
        int charCount[26] = {0};
        
        for(int i = 0; i < n; ++i) {
            ++charCount[s[i] - 'a'];
            --charCount[t[i] - 'a'];
        }
        
        for(int i = 0; i < 26; ++i) {
            if(charCount[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};
