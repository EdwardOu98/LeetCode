#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string res = s;
            for(int i = 0; i < s.length(); ++i) {
                string tmp = s.substr(i) + s.substr(0, i);
                
                if(tmp < res) {
                    res = tmp;
                }
            }
            
            return res;
        }
        
        sort(s.begin(), s.end());
        
        return s;
    }
};
