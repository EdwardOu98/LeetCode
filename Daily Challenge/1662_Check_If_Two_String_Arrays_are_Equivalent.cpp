#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0, p = 0, q = 0;
        
        while(i < m && p < n) {
            if(word1[i][j] == word2[p][q]) {
                ++j;
                ++q;
                if(j == word1[i].length()) {
                    ++i;
                    j = 0;
                }
                
                if(q == word2[p].length()) {
                    ++p;
                    q = 0;
                }
            }
            else {
                return false;
            }
        }
        
        return (i == m && j == 0) && (p == n && q == 0);
    }
};
