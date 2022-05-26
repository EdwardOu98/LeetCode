#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    struct Trie {
        int idx;
        Trie* children[26];
        Trie() {
            idx = -1;
            for(int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
    };

    Trie* root;
    vector<vector<int>> res;

    // Inputs:
    // - word: a word from the smalls array
    // - idx : the word's index in the smalls array
    void insert(string& word, int& idx) {
        Trie* tmp = root;
        for(char& c : word) {
            if(!tmp->children[c - 'a']) {
                tmp->children[c - 'a'] = new Trie();
            }
            tmp = tmp->children[c - 'a'];
        }
        // Record the word's index in the smalls array
        tmp->idx = idx;
    }

    // Inputs:
    // - sub: a substring of the big string
    // - idx: the index where the substring starts
    void search(string& sub, int idx) {
        Trie* tmp = root;
        for(char& c : sub) {
            if(!tmp->children[c - 'a']) {
                return;
            }
            tmp = tmp->children[c - 'a'];
            // If we see a word in the smalls array, add the current index
            // to the corresponding subarray in the result array
            if(tmp->idx != -1) {
                res[tmp->idx].push_back(idx);
            }
        }
    }

    vector<vector<int>> bruteForce(string& big, vector<string>& smalls) {
        vector<vector<int>> res;
        for(string& s : smalls) {
            vector<int> idx;
            // Search for s in big
            int pos = big.find(s);
            // If s is empty or we can't find s in big, directly add
            // the idx array to the result array
            if(pos == string::npos || s == "") {
                res.push_back(idx);
            }
            // If we find s in big
            else {
                // Add the index to the idx array and try to search for
                // s in the subarray after the index. Continue until
                // s is not found
                while(pos != string::npos) {
                    idx.push_back(pos++);
                    pos = big.find(s, pos);
                }
                res.push_back(idx);
            }
        }

        return res;
    }
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        return bruteForce(big, smalls);
        res.resize(smalls.size());
        root = new Trie();
        int m = big.length(), n = smalls.size();
        // Add the words in the smalls array to the trie
        for(int i = 0; i < n; ++i) {
            insert(smalls[i], i);
        }

        // For each of the substring, check whether they can form a word 
        // in the smalls array
        for(int i = 0; i < m; ++i) {
            string sub = big.substr(i);
            search(sub, i);
        }

        return res;
    }
};
