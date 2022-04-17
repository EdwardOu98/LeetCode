#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int N;
    
    void dfs(vector<string>& res, string& s,  string IP, int start, int parts) {
        // If we have reached the end of the input string and we have
        // gotten all four parts of the IP address, that means we restored
        // a valid IP address, add it to the result array
        if(start == N && parts == 4) {
            // Remove the trailing '.' in IP by taking the substring starting at
            // 0 and has a length of IP.length() - 1
            res.push_back(IP.substr(0, IP.length() - 1));
            return;
        }
        
        // If we have obtained x parts of the IP address, and the remaining
        // parts of the strings is longer than (4 - x) * 3 characters, that
        // means we have too many characters left for a valid IP adress. Thus,
        // we return to the previous level
        if(N - start > (4 - parts) * 3) {
            return;
        }
        
        // If we have obtained x parts of the IP adress, and the remaining
        // parts of the string is shorter than 4 - x characters, that means
        // we don't have enough characters to form the remaining parts of the
        // IP address. Thus, we return to the previous level.
        if(N - start < 4 - parts) {
            return;
        }
        
        int num = 0;
        // for each part of the IP address, we can have at most 
        // 3 characters. Thus the range for the current part is
        // from start to start + 2. 
        for(int i = start; i < start + 3; ++i) {
            // Calculate the value of the current substring
            num = num * 10 + (s[i] - '0');
            if(num <= 255) {
                IP += s[i];
                dfs(res, s, IP + ".", i + 1, parts + 1);
            }
            // If the current part contains a leading zero, that means
            // it's invalid and we don't need to continue this way
            if(num == 0) {
                return;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        
        N = s.length();
        vector<string> res;
        string IP;
        
        dfs(res, s, IP, 0, 0);
        
        return res;
    }
};
