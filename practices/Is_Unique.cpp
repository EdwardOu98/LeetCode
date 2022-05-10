#include <string>

using namespace std;

/* Problem:
 * Given an input string, check whether all characters in the
 * string are unique.
 *
 * Constraints:
 * Input string contains only lower-case English Letters
 */

class Solution {
private:
    bool counterSolution(string astr) {
        int counter[26] = {0};

        for(char& c : astr) {
            if(counter[c - 'a']) {
                return false;
            }
            ++counter[c - 'a'];
        }

        return true;
    }
public:
    bool isUnique(string astr) {
        if(astr.length() > 26) {
            return false;
        }
        int chars = 0;
        int idx;
        for(char& c : astr) {
            idx = 1 << (c - 'a');
            if(chars & idx) {
                return false;
            }
            chars |= idx;
        }
        return true;
    }
};
