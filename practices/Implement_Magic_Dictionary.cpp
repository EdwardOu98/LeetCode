#include <string>
#include <unordered_map>

using namespace std;

class MagicDictionary {
private:
    unordered_map<int, vector<string>> umap;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        umap.clear();
        int n;
        for(string& s : dictionary) {
            n = s.length();
            umap[n].push_back(s);
        }
    }
    
    bool search(string searchWord) {
        int n = searchWord.size();
        for(string& s : umap[n]) {
            bool flag = false;
            for(int i = 0; i < n; ++i) {
                if(searchWord[i] != s[i]) {
                    if(!flag) {
                        flag = true;
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
