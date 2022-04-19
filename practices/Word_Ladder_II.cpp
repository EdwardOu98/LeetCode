#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_set<string> dict;
    // Find all words in the dictionary that differ from
    // the input word by 1 character
    vector<string> neighbors(const string& _word) {
        int n = _word.length();
        vector<string> res;
        for(int i = 0; i < n; ++i) {
            for(char c = 'a'; c <= 'z'; ++c) {
                string word = _word.substr(0, i) + c + _word.substr(i+1);
                if(!dict.count(word)) {
                    continue;
                }
                res.push_back(word);
            }
        }
        
        return res;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(string& s : wordList) {
            if(s != beginWord) {
                dict.insert(s);
            }
        }
        
        unordered_map<string, vector<vector<string>>> umap;
        umap[beginWord] = {{beginWord}};
        
        while(!umap.empty()) {
            unordered_map<string, vector<vector<string>>> newMap;
            
            for(auto& [word, paths] : umap) {
                // If the current word is the end word, return the
                // corresponding transformation lists
                if(word == endWord) {
                    return umap[word];
                }
                
                for(const string& n : neighbors(word)) {
                    // For each path corrsponds to the current word, 
                    // we add one word from the neighbors to the path.
                    // And add this path to the transformation lists
                    // of the current neighbor in the new map; Notice
                    // the p here shouldn't be a reference type. Because
                    //  we only want a copy of p instead of the actual p
                    for(auto p : paths) {
                        p.push_back(n);
                        newMap[n].push_back(p);
                    }
                }
            }
            
            // After finishing calculation of the current level, we erase
            // words that had been used from the dictionary to prevent 
            // repeatitive calculations. 
            for(auto& [word, _] : newMap) {
                dict.erase(word);
            }
            
            umap.swap(newMap);
        }
        
        return {};
    }
};
