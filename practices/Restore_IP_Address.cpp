#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> res;
    int N;

    void dfs(string& s, string IP, int parts, int start) {
        // If we reach the end of input string and we have restored
        // all 4 parts of the IP address, we push add the IP to the
        // result array
        if(start == N && parts == 4) {
            res.push_back(IP.substr(0, N + 3));
            return;
        }

        // If the remaining number of characters are more than the
        // required number to form a valid IP address, return to 
        // the previous level
        if(N - start > (4 - parts) * 3) {
            return;
        }

        // If the remaining number of characers are less than the 
        // the minimum required number to form a valid IP address
        // , return to the previous level
        if(N - start < 4 - parts) {
            return;
        }

        int num = 0;
        for(int i = start; i < start + 3; ++i) {
            num = num * 10 + (s[i] - '0');
            if(num <= 255) {
                IP += s[i];
                dfs(s, IP + ".", parts + 1, i + 1);
            }

            // If this part contains a leading zero, return
            // to the previous level
            if(num == 0) {
                return;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        N = s.length();
        string IP = "";
        dfs(s, IP, 0, 0);

        return res;
    }
};
