#include <vector>
#include <map>
#include <set>
#include <utility>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    typedef pair<int, int> pii;
    typedef pair<TreeNode*, pii> pni;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // x - y - node value
        queue<pni> q;
        q.push({root, {0, 0}});
        
        // BFS building the map, the elements in the map are 
        // ordered by their x value (which column they are on),
        // then their y value (which row they are on),  and finally
        // the value itself
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            root = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(root->val);
            
            if(root->left) {
                q.push({root->left, {x-1, y+1}});
            }
            if(root->right) {
                q.push({root->right, {x+1, y+1}});
            }
        }
        
        vector<vector<int>> res;
        // For each column of the tree
        for(auto& [_, m] : nodes) {
            vector<int> tmp;
            // We add the values on the same row into the tmp vector
            for(auto& [_, vals] : m) {
                tmp.insert(tmp.end(), vals.begin(), vals.end());
            }
            // Then we add the column to the result vector
            res.push_back(tmp);
        }
        
        return res;
    }
};
