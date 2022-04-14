#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.find_last_not_of(' ');
        int res = 0;
        
        while(i >= 0 && s[i--] != ' ') {
            ++res;
        }
        
        return res;
    }
};
