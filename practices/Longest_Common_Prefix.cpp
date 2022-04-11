#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Idea: sort the input array. The longest common prefix
    // can be found by comparing the first and last string of
    // the sorted array.
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        string s1 = strs.front();
        string s2 = strs.back();
        string prefix;
        int minLen = min((int) s1.length(), (int) s2.length());
        
        int i = 0;
        
        while(i < minLen && s1[i] == s2[i]) {
            prefix += s1[i++];
        }
        
        return prefix;
    }
};
