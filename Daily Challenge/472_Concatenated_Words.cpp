#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    struct Node {
        Node* children[26];
        bool isEnd = false;
    };

    Node* root;

    void buildTrie(vector<string>& words) {
        Node* tmp;

        for(string& w : words) {
            tmp = root;
            for(char c : w) {
                if(tmp->children[c - 'a'] == nullptr) {
                    tmp->children[c - 'a'] = new Node();
                }
                tmp = tmp->children[c - 'a'];
            }
            tmp->isEnd = true;
        }
    }

    bool searchInTrie(string& word) {
        Node* tmp = root;

        for(char c : word) {
            if(tmp->children[c - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->children[c - 'a'];
        }

        return tmp->isEnd;
    }

    bool partitionAndSearch(string& word, int cuts) {
        if(word == "" && cuts >= 2) {
            return true;
        }

        if(word == "") {
            return false;
        }

        for(int i = 0; i < word.length(); ++i) {
            string prefix = word.substr(0, i+1);
            string suffix = word.substr(i+1);

            if(searchInTrie(prefix)) {
                if(partitionAndSearch(suffix, cuts + 1)) {
                    return true;
                }
            }
        }

        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new Node();
        buildTrie(words);

        vector<string> res;

        for(string w : words) {
            if(partitionAndSearch(w , 0)) {
                res.push_back(w);
            }
        }

        return res;
    }
};
