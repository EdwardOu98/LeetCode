#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    string strCount(string& s) {
        int count[26] = {0};
        for(char& c : s) {
            ++count[c - 'a'];
        }
        string t;
        for(int i = 0; i < 26; ++i) {
            t += string(count[i], 'a' + i);
        }
        
        return t;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> res;
        
        for(string s : strs) {
            umap[strCount(s)].push_back(s);
        }
        
        for(auto [_, strs] : umap) {
            res.push_back(strs);
        }
        
        return res;
    }
};
