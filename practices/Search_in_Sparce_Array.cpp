#include <vector>

using namespace std;

class Solution {
/* Problem:
 * Given a sorted array of strings (there are empty strings between each word).
 * Try to find the given word in the array
 */
public:
    int findString(vector<string>& words, string s) {
        int l = 0, r = words.size() - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;
            // If the current string is an empty string, we move m towards
            // l until an non-empty string
            while((m > l) && (words[m] == "")) {
                --m;
            }

            if(words[m] == s) {
                return m;
            }
            else if(words[m] < s) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        return -1;
    }
};
