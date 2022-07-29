#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n = pattern.length(), i;
        
        for(string& word : words) {
            if(word.length() != n) {
                continue;
            }
            unordered_map<char, char> umap;
            for(i = 0; i < n; ++i) {
                if(umap.count(pattern[i]) && umap[pattern[i]] != word[i]) {
                    break;
                }
                umap[pattern[i]] = word[i];
            }
            if(i == n) {
                bool visited[26] = {false};
                bool flag = false;
                
                for(auto& [_, val] : umap) {
                    if(visited[val - 'a']) {
                        flag = true;
                        break;
                    }
                    visited[val - 'a'] = true;
                }
                
                if(!flag) {
                    res.push_back(word);
                }
            }
        }
        
        return res;
    }
};
