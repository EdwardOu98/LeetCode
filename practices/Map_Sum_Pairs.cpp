#include <string>
#include <unordered_map>

using namespace std;

class MapSum {
private:
    typedef struct Trie {
        bool isEnd;
        int sum;
        Trie* children[26];
        Trie() {
            isEnd = false;
            sum = 0;
            // memset(children, NULL, sizeof(children));
            for(int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
    } Trie;

    void deleteTrie(Trie* root) {
        for(int i = 0; i < 26; ++i) {
            if(root->children[i]) {
                deleteTrie(root->children[i]);
            }
        }
        delete root;
    }

    Trie* root;
    unordered_map<string, int> umap; // 保存现有单词的键值对
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Trie();
    }

    ~MapSum() {
        deleteTrie(root);
    }
    
    void insert(string key, int val) {
        int diff = val - umap[key]; // 查看当前单词是否已经存在于前缀树中
                                    // 如果存在，则将每一个字母对应的和加上
                                    // 前后两次插入的值的差。否则直接插入
        Trie* p = root;
        for(char& c : key) {
            int ch = c - 'a';
            if(!p->children[ch]) {
                p->children[ch] = new Trie();
            }
            p = p->children[ch];
            p->sum += diff;
        }

        umap[key] = val;
        p->isEnd = true;
    }
    
    int sum(string prefix) {
        Trie* p = root;
        for(char& c : prefix) {
            int ch = c - 'a';
            if(!p->children[ch]) {
                return 0;
            }
            p = p->children[ch];
        }

        return p->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
