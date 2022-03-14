#include <string>
#include <vector>
#include <sstream> // std::stringstream

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty()) {
            return path;
        }
        
        string res, temp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss, temp, '/')) {
            if((temp == ".") || (temp == "")) {
                continue;
            }
            else if(temp != "..") {
                stk.push_back(temp);
            }
            else if(!stk.empty()) {
                stk.pop_back();
            }
        }
        
        for(string s : stk) {
            res += "/" + s;
        }
        
        return res.empty() ? "/" : res;
    }
};
