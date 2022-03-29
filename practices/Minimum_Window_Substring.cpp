#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size(), n = s.size();
        // If t is longer than s, return an empty string
        if(m > n) {
            return "";
        }
        // If both strings has length 1, then compare their 
        // first characters. If they are the same, return s;
        // Otherwise, return an empty string
        if(m == 1 && n == 1) {
            return s[0] == t[0] ? s : "";
        }

        int counter[256] = {0};
        int charTypes = 0; // Record how many different types of characters appeared in t
        for(char& c : t) {
            if(++counter[c] == 1) {
                ++charTypes;
            }
        }

        int left = 0, right = 0; // Left and right boundary of the substring
        int start = 0; // Starting position of the window
        for(int i = 0; i < n; ++i) {
            // Add a new character into the sliding window and decrement the corresponding
            // character count stored in counter. If a character ch1 appeared in t, then its
            // initial count should be greater than 0. When this count becomes zero, that 
            // means we have included enough ch1 in the window. thus, we can decrement the 
            // charTypes variable. If a character ch2 didn't appeared in t, then its initial
            // count should be 0. After decrementing the count will become negative, which
            // means this character could be excessive
            if(--counter[s[i]] == 0) {
                --charTypes;
            }
            // When charTypes become 0, that means we have included all characters in t into
            // the window. Then we just need to shorten the window size to get a minimum window
            if(charTypes == 0) {
                while(counter[s[start]] < 0) {
                    ++counter[s[start]];
                    ++start;
                }

                if((left == right) || (right - left > i - start + 1)) {
                    right = i + 1;
                    left = start;
                }
            }
        }

        return s.substr(left, right - left);
    }
};
