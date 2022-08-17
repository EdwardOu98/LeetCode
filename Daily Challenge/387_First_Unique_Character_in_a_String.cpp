#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
       int counter[26] = {0};
        
        for(char& c : s) {
            ++counter[c - 'a'];
        }
        
        for(int i = 0; i < s.length(); ++i) {
            if(counter[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
