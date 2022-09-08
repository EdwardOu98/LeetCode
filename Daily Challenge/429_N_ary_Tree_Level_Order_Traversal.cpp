#include <queue>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            while(n-- > 0) {
                root = q.front();
                q.pop();
                tmp.push_back(root->val);
                
                for(auto c : root->children) {
                    q.push(c);
                }
            }
            
            res.push_back(tmp);
        }
        
        return res;
    }
};
