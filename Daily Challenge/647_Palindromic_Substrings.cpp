#include <string>

using namespace std;

class Solution {
private:
    int expandFromCenter(string& s, int l, int r, int n) {
        int counter = 0;
        while(l >= 0 && r < n) {
            if(s[l] != s[r]) {
                break;
            }
            --l;
            ++r;
            ++counter;
        }
        
        return counter;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int counter = 0;
        
        for(int i = 0; i < n; ++i) {
            counter += expandFromCenter(s, i, i, n);
            counter += expandFromCenter(s, i, i+1, n);
        }
        
        return counter;
    }
};
