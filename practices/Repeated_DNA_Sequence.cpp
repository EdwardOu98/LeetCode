#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        // If the input sequence is less than 10, return
        // an empty array;
        if(n < 10) {
            return {};
        }
        unordered_map<string, int> umap;
        string str;
        vector<string> res;
        // Record the times of occurrences of each substring
        // with length of 10
        for(int i = 0; i < n - 9; ++i) {
            str = s.substr(i, 10);
            ++umap[str];
        }
        
        for(auto [str, count] : umap) {
            if(count > 1) {
                res.push_back(str);
            }
        }
        
        return res;
    }
};
