#include <vector>

using namespace std;

class Solution {
private:
    // Building the next array for KMP algorithm
    vector<int> buildNextArray(string& needle, int& n) {
        vector<int> next(n, 0);
        int i = 1, len = 0;
        
        while(i < n) {
            // If needle[i] == needle[len], we set next[i] to
            // len + 1
            if(needle[i] == needle[len]) {
                next[i++] = ++len;
            }
            // If they are not equal and we currently have a
            // matching pattern with non-zero length, we change
            // len to next[len - 1]
            else if (len) {
                len = next[len - 1];
            }
            // Otherwise, we set next[i] to 0
            else {
                next[i++] = 0;
            }
        }
        
        return next;
    }
public:
    int strStr(string haystack, string needle) {

        if(needle.empty()) {
            return 0;
        }
        
        int m = haystack.length(), n = needle.length();
        vector<int> next = buildNextArray(needle, n);
        int i = 0, j = 0;
        
        while(i < m) {
            // If the current character in both haystack
            // and needle are the same, wee movee to the
            // next character
            if(haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            
            // If j == n, which means we have found the needle
            // in haystack, we return i - j, which is the starting
            // position of the pattern in haystack
            if(j == n) {
                return i - j;
            }
            
            // If i is still in range and the current character in 
            // haystack and that in needle doesn't match, we check
            // whether j is greater than 0. If so, we update j to
            // next[j - 1]; Otherwise, we move forward in haystack
            if(i < m && haystack[i] != needle[j]) {
                j ? j = next[j - 1] : ++i;
            }
        }
        
        // If needle doesn't appear in haystack, we return -1
        return -1;
    }
};
