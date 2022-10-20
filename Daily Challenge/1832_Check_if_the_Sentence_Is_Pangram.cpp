#include <string>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int letters[26] = {0};
        
        for(char& c : sentence) {
            ++letters[c-'a'];
        }
        
        for(int i = 0; i < 26; ++i) {
            if(!letters[i]) {
                return false;
            }
        }
        
        return true;
    }
};
