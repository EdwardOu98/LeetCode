#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counter;
        
        for(string& word : words) {
            ++counter[word];
        }
        
        int m = s.length(), n = words.size(), wordLen = words[0].length();
        int substrLen = n * wordLen;
        int maxIdx = m - substrLen;
        
        vector<int> res;
        
        for(int i = 0; i <= maxIdx; ++i) {
            unordered_map<string, int> wordsFound;
            int j;
            for(j = 0; j < n; ++j) {
                string sub = s.substr(i + j * wordLen, wordLen);
                if(counter.count(sub)) {
                    ++wordsFound[sub];
                    if(wordsFound[sub] > counter[sub]) {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            
            if(j == n) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
