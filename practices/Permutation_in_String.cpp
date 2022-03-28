#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();

        // If s1 is longer than s2, then no need
        // to compare
        if(m > n) {
            return false;
        }

        // Number of occurrences of characters in s1
        vector<int> charsInS1(26, 0);
        for(char& c : s1) {
            ++charsInS1[c - 'a'];
        }

        // Number of occurences of characters in s2's substring
        vector<int> charsInS2(26, 0);
        int left = 0, right; // The left and right boundary of the sliding window

        for(right = 0; right < n; ++right) {
            // Add one character to the substring
            ++charsInS2[s2[right] - 'a'];
            // When the substring contains m characters, compare the contents of
            // two hash table. If they are the same, return true; Otherwise, continue
            if(right >= m - 1) {
                if(charsInS1 == charsInS2) {
                    return true;
                }
                // Remove the first character from the substring
                --charsInS2[s2[left] - 'a'];
                ++left;
            }
        }


        return false;
    }
};
