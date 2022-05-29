#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    struct Trie {
        bool isEnd;
        int maxDepth;
        Trie* child[26];
        Trie() {
            isEnd = false;
            maxDepth = 0;
            for(int i = 0; i < 26; ++i) {
                child[i] = NULL;
            }
        }
    };

    Trie* root;
    void insert(string& s) {
        Trie* tmp = root;
        for(char &c : s) {
            if(!tmp->child[c-'a']) {
                tmp->child[c-'a'] = new Trie();
            }
            tmp = tmp->child[c-'a'];
            if(tmp->maxDepth < s.length()) {
                tmp->maxDepth = s.length();
            }
        }
        tmp->isEnd = true;
    }

    vector<string> res;
    vector<string> tmp;
    void dfs(vector<Trie*>& nodes, vector<string>& words) {
        bool flag = false;

        for(Trie* node : nodes) {
            flag = true;
            if(!node->isEnd) {
                flag = false;
                break;
            }
        }

        if(flag) {
            if(res.empty() || res.size() * res[0].size() < tmp.size() * tmp[0].size()) {
                res = tmp;
            }
        }

        vector<Trie*> tmpNodes = nodes;

        for(string& s : words) {

            if(tmp.empty()) {
                nodes.resize(s.length(), root);
                tmpNodes = nodes;
            }

            if(tmp.empty() || (tmp[0].size() == s.length())) {
                int len = s.length();
                flag = true;

                for(int i = 0; i < len; ++i) {
                    char& c = s[i];
                    if(!nodes[i]->child[c - 'a'] || 
                    ((!res.empty()) && 
                    (nodes[i]->child[c-'a']->maxDepth * len <= res.size() * res[0].size()))) {
                        flag = false;
                        break;
                    }
                    else {
                        nodes[i] = nodes[i]->child[c-'a'];
                    }
                }

                if(flag) {
                    tmp.push_back(s);
                    dfs(nodes, words);
                    tmp.pop_back();
                }

                nodes = tmpNodes;
            }
        }
    }
public:
    vector<string> maxRectangle(vector<string>& words) {
        root = new Trie();
        for(string& s : words) {
            insert(s);
        }

        vector<Trie*> nodes;

        dfs(nodes, words);

        return res;
    }
};
