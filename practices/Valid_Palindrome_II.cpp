#include <string>

using namespace std;

class Solution {
private:
    bool isValid(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    }
public:
    bool validPalindrome(string& s) {
        // Two pointers
        int l = 0, r = s.length() - 1;
        // Iterate through the whole string. When an unmatched is found,
        // try to verify if the string can become a palindrome when the 
        // left or right characer is removed
        while(l < r) {
            if(s[l] != s[r]) {
                return isValid(s, l + 1, r) || isValid(s, l, r - 1);
            }
            ++l;
            --r;
        }

        return true;
    }
};
