#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    // void reverse(string& s, int l, int r) {
    //     while(l < r) {
    //         swap(s[l++], s[r--]);
    //     }
    // }
    
public:
    string reverseWords(string s) {
        
        
        int i, j;
        
        // Remove leading spaces
        i = s.find_first_not_of(' ');
        if(i == -1) {
            return "";
        }
        s.erase(s.begin(), s.begin() + i);
        
        i = 0;
        
        while(i < s.length()) {
            // If current character is not space, move forward on the string
            // until meeting a space
            if(s[i] != ' ') {
                j = i;
                while(j < s.length() && s[j] != ' ') {
                    ++j;
                }
                // reverse(s, i, j - 1);
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
            // If a current character is a space, remove all
            // spaces behind it until a non-space character is
            // found
            else {
                ++i;
                while(i < s.length() && s[i] == ' ') {
                    s.erase(s.begin() + i);
                }
            }
        }
        
        // reverse(s, 0, s.length() - 1);
        reverse(s.begin(), s.end());
        
        i = s.find_first_not_of(' ');
        s.erase(s.begin(), s.begin() + i);
        
        return s;
    }
};
