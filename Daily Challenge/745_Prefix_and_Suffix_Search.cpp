#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class WordFilter {
private:
    struct TrieNode {
        int weight;
        unordered_map<int, TrieNode*> children;
        TrieNode() {
            weight = 0;
        }
    };
    
    TrieNode* root;
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        int weight = 0;
        
        for(string& word : words) {
            TrieNode* curr = root;
            curr->weight = weight;
            int L = word.length();
            
            for(int i = 0; i < L; ++i) {
                TrieNode* tmp = curr;
                for(int j = i; j < L; ++j) {
                    int code = (word[j] - '`') * 27;
                    if(!tmp->children.count(code)) {
                        tmp->children[code] = new TrieNode();
                    }
                    tmp = tmp->children[code];
                    tmp->weight = weight;
                }
                
                tmp = curr;
                
                for(int j = L - 1 - i; j >= 0; --j) {
                    int code = (word[j] - '`');
                    if(!tmp->children.count(code)) {
                        tmp->children[code] = new TrieNode();
                    }
                    tmp = tmp->children[code];
                    tmp->weight = weight;
                }
                
                int code = (word[i] - '`') * 27 + (word[L - 1 - i] - '`');
                if(!curr->children.count(code)) {
                    curr->children[code] = new TrieNode();
                }
                curr = curr->children[code];
                curr->weight = weight;
            }
            ++weight;
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* curr = root;
        
        int i = 0, j = suffix.length() - 1;
        while(i < prefix.length() || j >= 0) {
            char c1 = i < prefix.length() ? prefix[i] : '`';
            char c2 = j >= 0 ? suffix[j] : '`';
            int code = (c1 - '`') * 27 + (c2 - '`');
            curr = curr->children[code];
            if(!curr) {
                return -1;
            }
            ++i;
            --j;
        }
        
        return curr->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
