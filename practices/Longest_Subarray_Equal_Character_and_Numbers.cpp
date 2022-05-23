#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int check(string& s) {
        // If the string is a character, return 1;
        // Otherwise, return -1
        return s[0] > '9' ? 1 : -1;
    }
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        int prefixSum[n+1];
        prefixSum[0] = 0;

        for(int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i-1] + check(array[i-1]);
        }

        int left = -1, right = -1; // The left and right boundary of the
                                   // longest continuous substring with equal
                                   // number of characters and numbers
        unordered_map<int, int> mp;
        for(int i = 0; i <= n; ++i) {
            if(mp.count(prefixSum[i])) {
                int len = i - mp[prefixSum[i]];
                if(len > (right - left)) {
                    left = mp[prefixSum[i]];
                    right = i;
                }
            }
            else {
                mp[prefixSum[i]] = i;
            }
        }

        if(left < 0) {
            return {};
        }
        return vector<string>(array.begin() + left, array.begin() + right);
    }
};
