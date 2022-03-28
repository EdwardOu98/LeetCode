#inlcude <algorithm>
#include <string>

using namespace std;

class Solution {
private: 
    int OptimizedSolution(string& s) {
        // If s is an empty string, then return 0
        if(s.empty()) {
            return 0;
        }

        int n = s.length();
        int left = 0, right = 0; // left and right boundaries of the sliding window
        int maxLen = 0;
        int used[256] = {0}; // A table to record occurences of characters

        while(right < n) {
            // Continuously add a new character into the window until a recurrence occurred
            while(right < n && !used[s[right]]) {
                ++used[s[right]];
                ++right;
            }

            // Calculate the max length
            maxLen = max(maxLen, right - left);

            // Remove the leading characters in the window until the recurrence resolved
            while(left < right && used[s[right]]) {
                --used[s[left]];
                ++left;
            }
        }

        return maxLen;
    }

    int initialSolution(string& s) {
        // If s is an empty string, then return 0
        if(s.empty()) {
            return 0;
        }

        int n = s.length();
        int left, right; // left and right boundaries of the sliding window
        int maxLen = 0, currLen;
        int used[256]; // A table to record occurences of characters

        for(left = 0; left < n; ++left) {
            memset(used, 0, sizeof(used)); // Initialize the table
            currLen = 0;
            for(right = left; right < n; ++right) {
                if(used[s[right]]) {
                    break;
                }
                ++currLen;
                ++used[s[right]];
            }
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
public:
    int lengthOfLongestSubstring(string& s) {
        return OptimizedSolution(s);
    }
};
