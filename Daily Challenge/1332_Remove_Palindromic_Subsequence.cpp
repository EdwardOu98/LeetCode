#include <string>

using namespace std;

class Solution {
// Idea: We can make use of the fact that the string contains only 2 possible characters.
// The final answer will not be greater than 2 because, unlike a subarray, a subsequence
// doesn't have to be contiguous in the original array/string. And because a string that
// contains only one type of character is always palindromic, we can delete one type of
// characters first and then another to delete all palindromic subsequence in 2 operations
// at maximum. If the input string  is palindromic, then we can simply delete the entire
// string in 1 operation. If the input string is empty, then no operation is needed. 
public:
    int removePalindromeSub(string s) {
        // If the string is empty, we can delete it with no operation
        if(s.empty()) {
            return 0;
        }
        
        for(int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            // If the input string contains 2 types of characters and it's not palindromic, 
            // then we need at least 2 operations two delete the entire string
            if(s[i] != s[j]) {
                return 2;
            }
        }
        
        // If the input string contains only 1 types of character or it's palindromic, then
        // we only need 1 operation to delete the entire string
        return 1;
    }
};
