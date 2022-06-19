#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    struct TrieNode {
        bool isWord;
        TrieNode* children[26];
        TrieNode() {
            isWord = false;
            memset(children, NULL, sizeof(children));
        }
    };
    
    TrieNode* root;
    
    void dfs(TrieNode* curr, string& word, vector<string>& res) {
        // If the result list has 3 words already, return to
        // the upper level
        if(res.size() == 3) {
            return;
        }
        // If the current node contains a word, add it to the result list
        if(curr->isWord) {
            res.push_back(word);
        }
        
        // Find all possible paths in lexical order
        for(char c = 'a'; c <= 'z'; ++c) {
            if(curr->children[c - 'a']) {
                word += c;
                dfs(curr->children[c - 'a'], word, res);
                word.pop_back();
            }
        }
    }
    
    vector<string> searchPrefix(string& prefix) {
        TrieNode* curr = root;
        vector<string> res;
        
        for(char& c : prefix) {
            // If the current character doesn't match with
            // any prefix in the trie, return the result array
            if(!curr->children[c - 'a']) {
                return res;
            }
            // Move to the next node
            curr = curr->children[c - 'a'];
        }
        
        // Perform dfs with the prefix
        dfs(curr, prefix, res);
        
        return res;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        
        // Insert the dictionary into the trie
        for(string& w : products) {
            TrieNode* tmp = root;
            for(char& c : w) {
                int idx = c - 'a';
                if(!tmp->children[idx]) {
                    tmp->children[idx] = new TrieNode();
                }
                tmp = tmp->children[idx];
            }
            tmp->isWord = true;
        }
        
        string prefix;
        vector<vector<string>> res;
        // Each time we add a character to the prefix string
        // and perform dfs
        for(char& c : searchWord) {
            prefix += c;
            res.push_back(searchPrefix(prefix));
        }
        
        return res;
    }
};
