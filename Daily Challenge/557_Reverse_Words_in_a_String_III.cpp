#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, l = 0, r = 0;
        
        while(i < n) {
            while(i < n && s[i] != ' ') {
                ++i;
            }
            r = i - 1;
            while(l < r) {
                swap(s[l], s[r]);
                ++l;
                --r;
            }
            ++i;
            l = i;
        }
        
        return s;
    }
};
