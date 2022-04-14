#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 思路：将输入的单词数组按照从长到短的长度排序，然后通过将每个单词逆序插入
    // 的方式构建前缀树。如果一个单词是另一个单词的前缀，则不需要将其长度计入结果
private:
    static bool comp(string& a, string& b) {
        return a.size() > b.size();
    }

    typedef struct Trie {
        bool isEnd;
        Trie* children[26];
        Trie() {
            isEnd = false;
            for(int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
    } Trie;

    Trie* root;

    // 将单词逆序插入前缀树中
    void insert(string& s) {
        Trie* p = root;
        for(int i = s.length() - 1; i >= 0; --i) {
            int ch = s[i] - 'a';
            if(!p->children[ch]) {
                p->children[ch] = new Trie();
            }
            p = p->children[ch];
        }
        p->isEnd = true;
    }

    // 检查一个逆序单词是否是另一个逆序单词的前缀
    bool isPrefix(string& s) {
        Trie* p = root;
        
        for(int i = s.length() - 1; i >= 0; --i) {
            int ch = s[i] - 'a';
            if(!p->children[ch]) {
                return false;
            }
            p = p->children[ch];
        }
        return true;
    }

    void deleteTrie(Trie* root) {
        for(int i = 0; i < 26; ++i) {
            if(root->children[i]) {
                deleteTrie(root->children[i]);
            }
        }
        delete root;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int res = 0;
        root = new Trie();
        for(string& s : words) {
            // 如果一个逆序单词不是另一个逆序单词的前缀，则
            // 将其加入前缀树，并更新助记字符串的长度。新增
            // 长度为单词长度+1(+1来自助记字符串中的‘#’)
            if(!isPrefix(s)) {
                insert(s);
                res += s.length() + 1;
            }
        }

        deleteTrie(root);

        return res;
    }
};
