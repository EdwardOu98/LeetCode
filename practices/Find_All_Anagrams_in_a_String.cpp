#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.length(), n = s.length();
        // If p is longer than s, then just return an empty vector
        if(m > n) {
            return {};
        }
        vector<int> res;
        vector<int> pFreq(26, 0); // characters in string p

        for(char& c : p) {
            ++pFreq[c - 'a'];
        }

        vector<int> sFreq(26, 0); // characters in current window
        int left = 0, right; // left and right boundary of sliding window

        for(right = 0; right < n; ++right) {
            ++sFreq[s[right] - 'a'];
            if(right >= m - 1) {
                if(sFreq == pFreq) {
                    res.push_back(left);
                }
                --sFreq[s[left] - 'a'];
                ++left;
            }
        }

        return res;
    }
};
