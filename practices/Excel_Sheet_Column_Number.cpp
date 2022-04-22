#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        
        // For each character in the column title, 
        // we calculate its corresponding number and
        // add to the result;
        for(char& c : columnTitle) {
            res = res * 26 + (c - 'A') + 1;
        }
        
        return res;
    }
};
