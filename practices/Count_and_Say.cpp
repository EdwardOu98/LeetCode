#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        if(n == 2) {
            return "11";
        }
        string pre = countAndSay(n - 1);
        int count = 1, len = pre.length();
        string res = "";
        for(int i = 1; i < len; ++i) {
            if(pre[i] != pre[i-1]) {
                res.push_back(count + '0');
                res.push_back(pre[i-1]);
                count = 1;
            }
            else {
                ++count;
            }
            if(i == len - 1) {
                res.push_back(count + '0');
                res.push_back(pre[i]);
            }
        }
        
        return res;
    }
};
