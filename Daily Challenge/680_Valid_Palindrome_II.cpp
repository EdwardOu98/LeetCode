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
        int l = 0, r = s.length() - 1;
        
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
