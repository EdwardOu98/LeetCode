#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if(n == 1) {
            return true;
        }
        bool isFirstCapital = false, isSecondCapital = false;
        
        if(isupper(word[0]) && isupper(word[1])) {
            for(int i = 2; i < n; ++i) {
                if(islower(word[i])) {
                    return false;
                }
            }
        }
        else {
            for(int i = 1; i < n; ++i) {
                if(isupper(word[i])) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
