#include <vector>
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
// Idea: use level-order traversal, the last node in each level is the result we want
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        int n, i;
        TreeNode* node;
        vector<int> res;
        
        while(!q.empty()) {
            n = q.size();
            for(i = 0; i < n; ++i) {
                // Get the node at the front of the queue
                node = q.front();
                q.pop();
                // If the current node is the tail of the queue,
                // push its value into the result array
                if(i == n - 1) {
                    res.push_back(node->val);
                }
                
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        
        return res;
    }
};
