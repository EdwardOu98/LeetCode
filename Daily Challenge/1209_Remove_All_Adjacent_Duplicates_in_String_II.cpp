#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        int charCount[n];
        charCount[0] = 1;
        int j = 0;
        for(int i = 0; i < n; ++i, ++j) {
            s[j] = s[i];
            // If the current character is the same as the previous character,
            // increment the character count. Otherwise, reset charCount to 1
            if(j && s[j] == s[j-1]) {
                charCount[j] = charCount[j-1] + 1;
            }
            else {
                charCount[j] = 1;
            }
            
            // When we have k consecutive duplicate characters, we reset the j's
            // position
            if(charCount[j] == k) {
                j -= k;
            }
        }
        
        return s.substr(0, j);
    }
};
