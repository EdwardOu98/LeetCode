#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Count the number of characters in each word
    vector<int> countChar(string& word) {
        vector<int> counter(26, 0);
        
        for(char& c : word) {
            ++counter[c - 'a'];
        }
        
        return counter;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> maxCount(26, 0);
        
        for(string& w : words2) {
            vector<int> count = countChar(w);
            
            for(int i = 0; i < 26; ++i) {
                maxCount[i] = max(maxCount[i], count[i]);
            }
        }
        
        for(string& w : words1) {
            vector<int> count = countChar(w);
            int i;
            for(i = 0; i < 26; ++i) {
                if(count[i] < maxCount[i]) {
                    break;
                }
            }
            if(i == 26) {
                res.push_back(w);
            }
        }
        
        return res;
    }
};
