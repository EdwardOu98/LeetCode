#include <vector>

using namespace std;

class Solution {
private:
    typedef struct Trie {
        Trie* children[2];
        Trie() {
            children[0] = children[1] = NULL;
        }
    } Trie;

    Trie* root;

    void insert(int num) {
        Trie* p = root;
        for(int i = 31; i >= 0; --i) {
            int b = (num >> i) & 1;
            if(!p->children[b]) {
                p->children[b] = new Trie();
            }
            p = p->children[b];
        }
    }

    int maxXOR(int num) {
        Trie* p = root;
        int res = 0;

        for(int i = 31; i >= 0; --i) {
            int b = (num >> i) & 1;
            if(p->children[!b]) {
                res |= 1 << i;
                p = p->children[!b];
            }
            else {
                p = p->children[b];
            }
        }

        return res;
    }

    void deleteTrie(Trie* root) {
        for(int i = 0; i < 2; ++i) {
            if(root->children[i]) {
                deleteTrie(root->children[i]);
            }
        }
        delete root;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Trie();

        for(int& num : nums) {
            insert(num);
        }

        int res = INT_MIN;

        for(int& num : nums) {
            res = max(res, maxXOR(num));
        }

        return res;
    }
};
