#include <vector>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        bool hasDigit = false;
        bool hasDot = false;
        bool hasExp = false;
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == '+' || s[i] == '-') {
                if(i && (s[i-1] != 'e' && s[i-1] != 'E')) {
                    return false;
                }
            }
            else if(isdigit(s[i])) {
                hasDigit = true;
            }
            else if((s[i] == 'e' || s[i] == 'E') && hasDigit && !hasExp) {
                hasExp = true;
                hasDigit = false;
            }
            else if(s[i] == '.' && !hasDot && !hasExp) {
                hasDot = true;
            }
            else {
                return false;
            }
        }
        
        return hasDigit;
    }
};
