#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    typedef struct Node {
        string word;
        Node* children[26];
        Node() {
            word = "";
            for(int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    } Node;
    
    Node* root;
    vector<string> res;
    int m, n; // Dimension of the board
    
    void insert(vector<string>& words) {
        Node* temp;
        int i;
        for(string& s : words) {
            temp = root;
            for(char& c : s) {
                i = c - 'a';
                if(!temp->children[i]) {
                    temp->children[i] = new Node();
                }
                temp = temp->children[i];
            }
            temp->word = s;
        }
    }
    
    void clear(Node* root) {
        for(int i = 0; i < 26; ++i) {
            if(root->children[i]) {
                clear(root->children[i]);
            }
        }
        
        delete root;
    }
    
    void search(vector<vector<char>>& board, int x, int y, Node* node) {
        // If the current index is out of bound, exit the function
        if(x < 0 || x >= m || y < 0 || y >= n) {
            return;
        }
        char c = board[x][y];
        // If the current cells had been visited before or the character
        // in the current cell doesn't belong to any word, return
        if(c == '*' || !node->children[c - 'a']) {
            return;
        }
        
        // move down on the trie
        node = node->children[c - 'a'];
        
        // If the current node contains a word, add it to the result array
        if(!node->word.empty()) {
            res.push_back(node->word);
            node->word = "";
        }
        
        // Mark the current cell as visited
        board[x][y] = '*';
        search(board, x + 1, y, node);
        search(board, x - 1, y, node);
        search(board, x, y + 1, node);
        search(board, x, y - 1, node);
        board[x][y] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        root = new Node();
        // Create a trie with the list of words
        insert(words);
        for(int x = 0; x < m; ++x) {
            for(int y = 0; y < n; ++y) {
                search(board, x, y, root);
            }
        }
        // delete the trie after all searches are done
        clear(root);
        
        return res;
    }
};
