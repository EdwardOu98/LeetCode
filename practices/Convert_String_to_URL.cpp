#include <string>

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int pos = S.length() - 1; // Insert position
        int i = length - 1; // End of input string
        string sp = "%20";

        while(i >= 0) {
            // If the current character is not a space, move it
            // to the end of the string
            if(S[i] != ' ') {
                S[pos] = S[i];
                --pos;
                --i;
            }
            // If the current character is a space, replace it with
            // "%20" and move it to the end of the string
            else {
                int l = 2;
                while(l >= 0) {
                    S[pos] = sp[l];
                    --pos;
                    --l;
                }
                --i;
            }
        }

        // Ignore leading characters resulted from the extra space at the
        // end of the original string
        return S.substr(pos + 1);
    }
};
