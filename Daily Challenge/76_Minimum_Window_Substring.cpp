#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n || m == 0 || n == 0) {
            return "";
        }
        
        unordered_map<char, int> umap;  // Record how many times each character
                                        // in t appears
        for(char& c : t) {
            ++umap[c];
        }
        
        int counter = n, start = 0, end = 0, length = INT_MAX, head = 0;
        while(end < m) {
            // If the current character in s is in t and it hasn't reach
            // its number of occurences, we decrement the counter
            if(umap[s[end++]]-- > 0) {
                --counter;
            }
            
            // When the counter is zero, that means we have included all
            // characrers in t in the window. Now we remove the characters
            // one by one from the left to shrink the window with all characters
            // in t still included
            while(counter == 0) {
                // update window size
                if(end - start < length) {
                    head = start;
                    length = end - start;
                }
                
                // If we remove one character and that character belongs to
                // t, we increment the counter so that we can leave the loop
                // and start looking for a new window with all characters in
                // t
                if(++umap[s[start++]] > 0) {
                    ++counter;
                }
            }
        }
        
        // After we iterate through the entire string s, if length is still
        // INT_MAX, that means we failed to find a window with all characters
        // in t, thus we return an empty string. Otherwise we return a substring
        // of s starting at head with the length of the size of the window
        return length == INT_MAX ? "" : s.substr(head, length);
    }
};
