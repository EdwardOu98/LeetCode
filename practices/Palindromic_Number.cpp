#include <string>

using namespace std;

class Solution {
private:
    // Reverse the lower half of the input number
    //  and compare it with the upper half
    bool constantSpace(int x) {
        // If the input number is negative or it's
        // a non-zero multiple of 10, the number is
        // definitely not palindrome
        if(x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        }
        
        // If the input number contains only one digit
        // from 0 to 9, the number is plaindromic
        if(x >= 0 && x <= 9) {
            return true;
        }
        
        int revNum = 0;
        
        // Stop conversion until the reversed lower-half
        // is greater than or equal to the remaining upper-half
        while(revNum < x) {
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }
        
        // If the input number contains even number of digits, then
        // the number is palindromic when the reversed lower-half is 
        // equal to the upper-half; If the input number contains odd 
        // number of digits, then the number is plaindromic when the 
        // upper-half is equal to the reversed lower-half divided by
        // 10 because the reversed lower-half contains one more digit
        // than the upper-half
        return (revNum == x) || (revNum / 10 == x);
    }
    
    // Convert input integer to string and then
    // deetermine whether it's palindromic
    bool linearSpace(int x) {
        string s = to_string(x);
        int i = 0, j = s.length() - 1;
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
    bool isPalindrome(int x) {
        return constantSpace(x);
    }
};
