#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];
        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
    };
    
    TrieNode* root;
    
    // Insert a word into the trie in reversed order
    // E.g. Instead of inserting the word "ab", we insert
    // "ba"
    void insert(string& s) {
        TrieNode* tmp = root;
        for(int i = s.length() - 1; i >= 0; --i) {
            int idx = s[i] - 'a';
            if(!tmp->children[idx]) {
                tmp->children[idx] = new TrieNode();
            }
            tmp = tmp->children[idx];
        }
        tmp->isEnd = true;
    }
    
    // Check whether a word is the prefix of another word
    bool isPrefix(string& s) {
        TrieNode* tmp = root;
        
        for(int i = s.length() - 1; i >= 0; --i) {
            int idx = s[i] - 'a';
            if(!tmp->children[idx]) {
                return false;
            }
            tmp = tmp->children[idx];
        }
        
        return true;
    }
    
    static bool comp(string& a, string& b) {
        return a.length() > b.length();
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        root = new TrieNode();
        int res = 0;
        for(string& word : words) {
            if(!isPrefix(word)) {
                insert(word);
                res += word.length() + 1;
            }
        }
        
        return res;
    }
};
