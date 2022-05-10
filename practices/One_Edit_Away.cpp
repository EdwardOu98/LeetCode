#include <string>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.length(), n = second.length();
        int diff = abs(m - n);
        // If the two strings' difference in length is more
        // than 1, then it's not possible make the two strings
        if(diff > 1) {
            return false;
        }
        // If first is the shorter one, we swap their content
        // so that we always have first as the longer one
        if(m < n) {
            return oneEditAway(second, first);
        }

        int edit = 0; // Number of edits required
        for(int i = 0; i < n; ++i) {
            // Because second is always the shorter one, we don't need
            // to consider the case of deleting one character to make
            // first and second the same. Now that we only need to consider
            // addition and replacement, we can simply the condition to
            // check whether we can turn second into first with one edit.
            // We keep track of the number of edits on the fly. When
            // first and second has the same length, i - diff * edit will
            // always equal to i. When we see a character difference, we
            // increment edit. When the number of edit is larger than 1,
            // we know that we can't turn second to first with only one edit.
            // Similarly, when first and second have different length, 
            // i - diff * edit will equal to i when we don't have any edits, 
            // and will be 1 less than i when we have 1 edit (which corresponds
            // to adding a character to second). 
            if(first[i] != second[i - diff * edit] && ++edit > 1) {
                return false;
            }
        }

        return true;
    }
};
