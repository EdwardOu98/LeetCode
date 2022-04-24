#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.begin(), rev.end()); // Get the reverse of s
        string new_s = s + "#" + rev; // Concatenate rev and s, separating them with
                                        // a '#' so that rev and s won't be mixed 
                                        // together when calculating the next array
                                        // in KMP algorithm
        int n = s.length(), new_n = new_s.length();
        int next[new_n];                // The next array for KMP algorithm
        memset(next, 0, sizeof(next));
        int i, t;
        // Find the longest prefix that matches the suffix
        for(i = 1; i < new_n; ++i) {
            t = next[i-1];
            while(t > 0 && new_s[i] != new_s[t]) {
                t = next[t-1];
            }
            if(new_s[i] == new_s[t]) {
                ++t;
            }
            next[i] = t;
        }
        
        
        return rev.substr(0, n - next[new_n - 1]) + s;
    }
};
