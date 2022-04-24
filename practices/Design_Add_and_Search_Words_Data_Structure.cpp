#include <string>
#include <cstring>

using namespace std;

class WordDictionary {
private:
    typedef struct Node {
        bool isEnd;
        Node* children[26];
        Node() {
            isEnd = false;
            for(int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    } Node;
    
    bool search(string& s, int idx, Node* root) {
        // When we reeach the end of the string
        // check whether this is the end of a word
        if(idx == s.length()) {
            return root->isEnd;
        }
        
        // If the current character is not '.', go
        // to the corresponding node. If the node
        // is not NULL, continue to search for the
        // next character; Otherwise, return false
        if(s[idx] != '.') {
            root = root->children[s[idx] - 'a'];
            return root ? search(s, idx + 1, root) : false;
        }
        
        // If the current character is '.', try
        // each of the character in the current node's
        // children. If we can find a word, return true.
        // Otherwise, return false;
        for(int i = 0; i < 26; ++i) {
            if(root->children[i] && search(s, idx + 1, root->children[i])) {
                return true;
            }
        }
        
        return false;
    }
    
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    ~WordDictionary() {
        clear(root);
    }
    
    void clear(Node* node) {
        for(int i = 0; i < 26; ++i) {
            if(node->children[i]) {
                clear(node->children[i]);
            }
        }
        
        delete node;
    }
    
    void addWord(string word) {
        Node* temp = root;
        int i;
        
        for(char& c : word) {
            i = c - 'a';
            if(!temp->children[i]) {
                temp->children[i] = new Node();
            }
            temp = temp->children[i];
        }
        
        temp->isEnd = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
