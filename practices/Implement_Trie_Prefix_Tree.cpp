#include <string>

using namespace std;

class Trie {
private:
    typedef struct TrieNode {
        bool end; // 指明当前结点是否为单词的词尾
        TrieNode* children[26]; // 保存当前字母的后一个字母的指针
        TrieNode() {
            end = false;
            for(int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
    } TrieNode;

    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        deleteNode(root);
    }

    void deleteNode(TrieNode* node) {
        for(int i = 0; i < 26; ++i) {
            if(node->children[i]) {
                deleteNode(node->children[i]);
            }
        }
        delete node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        int idx;
        for(char& c : word) {
            idx = c - 'a';
            if(!temp->children[idx]) {
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
        temp->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        int idx;
        for(char& c : word) {
            idx = c - 'a';
            if(!temp->children[idx]) {
                return false;
            }
            temp = temp->children[idx];
        }

        return temp && temp->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        int idx;
        for(char& c : prefix) {
            idx = c - 'a';
            if(!temp->children[idx]) {
                return false;
            }
            temp = temp->children[idx];
        }

        return temp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
