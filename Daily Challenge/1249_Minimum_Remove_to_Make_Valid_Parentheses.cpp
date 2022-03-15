#include <string>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length(), count = 0;
        // 从左往右扫描字符串，如果遇到(则count+1；如果遇到)且count不为0，
        // 则count-1；如果count为0，则说明这个)不符合规则，将它变为*
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                ++count;
            }
            else if(s[i] == ')') {
                if(count) {
                    --count;
                }
                else {
                    s[i] = '*';
                }
            }
        }
        
        // 从右往左扫描字符串，如果遇到)则count+1；如果遇到(且count不为0，
        // 则count-1；如果count为0，则说明这个(不符合规则，将它变为*
        count = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == ')') {
                ++count;
            }
            else if(s[i] == '(') {
                if(count) {
                    --count;
                }
                else {
                    s[i] = '*';
                }
            }
        }
        
        string res;
        for(char c : s) {
            if(c != '*') {
                res.push_back(c);
            }
        }
        
        return res;
    }
};
