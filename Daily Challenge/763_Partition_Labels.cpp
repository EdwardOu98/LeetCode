#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Time Complexity: O(n) as we iterate through the string
    // Space Complexity: O(1) as the only auxiliary space used is
    // an array of length 26 where we use to keep track of the 
    // last occurrence of each character. 
    vector<int> partitionLabels(string s) {
        int lastOccur[26] = {0}, n = s.length();
        
        // Record the last occurrence of each letter
        for(int i = 0; i < n; ++i) {
            lastOccur[s[i] - 'a'] = i;
        }
        
        int j = 0, anchor = 0;
        vector<int> res;
        
        // Iterate through the array again, this time identify
        // the label of partition. With anchor being the beginning
        // of the partition and j being the end, we use the condition
        // i == j to check that we are at the end of a partition. 
        // Then, we calculate the length of this partion by the formula
        // i - anchor + 1 and push the result into the return array. After
        // that we update anchor to i + 1.
        for(int i = 0; i < n; ++i) {
            j = max(j, lastOccur[s[i] - 'a']);
            if(i == j) {
                res.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        
        return res;
    }
};
