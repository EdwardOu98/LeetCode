#include <string>
#include <deque>
#include <cmath>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        if(n < 2) {
            return s;
        }
        
        deque<char> dq;
        
        for(int i = 0; i < n; ++i) {
            if(dq.empty() || (abs(dq.back() - s[i]) != 32)) {
                dq.push_back(s[i]);
            }
            else {
                dq.pop_back();
            }
        }
        
        return string(dq.begin(), dq.end());
    }
};
