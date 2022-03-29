#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while(i < j) {
            // If s[i] is not a number or an English character, 
            // increment i
            if(!isalnum(s[i])) {
                ++i;
            }
            // If s[j] is not a number or an English character, 
            // decrement j
            else if(!isalnum(s[j])) {
                --j;
            }
            else {
                if(tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                ++i;
                --j;
            }
        }

        return true;
    }
};
