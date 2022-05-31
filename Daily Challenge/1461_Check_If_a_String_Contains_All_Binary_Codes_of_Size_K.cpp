#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> uset;
        int numCode = 1 << k; // For binary code of length k, there are a total of 2^k of them
        
        int n = s.length();
        
        for(int i = 0; i + k <= n; ++i) {
            // Get a substring of length k
            string sub = s.substr(i, k);
            // Check whether we have seen this substring before
            if(!uset.count(sub)) {
                // If we haven't seen this substring before, add it to the
                // hash set and decrement the count of binary code we need
                uset.insert(sub);
                --numCode;
                
                // If the count of binary code has reached 0, we have found
                // all the binary code of length k, return true
                if(numCode == 0) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
