#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, bool> umap;
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        // If the two strings don't have the same length, return false;
        if(n != s2.length()) {
            return false;
        }
        // If both strings have length 1, compare the character
        if(n == 1) {
            return s1 == s2;
        }
        // If s1 and s2 are the same, return truel
        if(s1 == s2) {
            return true;
        }
        
        // Concatenate the two strings as the hashing key
        string hashStr = s1 + "/" + s2;
        
        // If this case has been calculated before, return the previous result
        if(umap.count(hashStr)) {
            return umap[hashStr];
        }
        
        // Check whether the two strings have the same character set
        int charSet[26] = {0};
        int i;
        for(i = 0; i < n; ++i) {
            ++charSet[s1[i] - 'a'];
            --charSet[s2[i] - 'a'];
        }
        
        // If they don't have the same character set, return false;
        for(i = 0; i < 26; ++i) {
            if(charSet[i] != 0) {
                return umap[hashStr] = false;
            }
        }
        
        for(i = 1; i < n; ++i) {
            // Divide the strings into 4 substrings, and check whether they are scramble of each other
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return umap[hashStr] = true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n-i))) {
                return umap[hashStr] = true;
            }
        }
        
        return umap[hashStr] = false;
    }
};
