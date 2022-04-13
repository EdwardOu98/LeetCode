#include <string>
#include <sstream>

using namespace std;

class Trie {
private: 
    struct Node{
        bool end;
        string word;
        Node* children[26];
        Node(){
            end = false;
            memset(children, NULL, sizeof(children));
        }
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Destructor **/
    ~Trie() {
        clear(root);
    }
    
    void clear(Node* root){
        for(int i = 0; i < 26; i++){
            if(root->children[i]){
                clear(root->children[i]);
            }
        }
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* tmp = root;
        for(const char c : word){
            if(!tmp->children[c - 'a']){
                tmp->children[c - 'a'] = new Node();
            }
            else if(tmp->children[c - 'a']->end){
                tmp = nullptr;
                break;
            }
            tmp = tmp->children[c - 'a'];
        }
        if(tmp){
            tmp->end = true;
            tmp->word = word;
        }
        
    }
    
    string replace(string s){
        Node* tmp = root;
        string res = "";
        for(const char& c : s){
            tmp = tmp->children[c - 'a'];
            if(!tmp){
                break;
            }
            else if(tmp->end){
                res = tmp->word;
                break;
            }
        }
        return res.empty() ? s : res;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string res = "";
        string token;
        Trie t;
        for(const string& s : dictionary){
            t.insert(s);
        }
        
        while(getline(ss, token, ' ')){
            res += (t.replace(token) + " ");
        }
        
        return res.substr(0, res.size() - 1);
    }
};
