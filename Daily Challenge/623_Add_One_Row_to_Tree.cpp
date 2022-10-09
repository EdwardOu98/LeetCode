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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        
        while(d < depth - 1) {
            int qSize = q.size();
            
            while(qSize > 0) {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
                --qSize;
            }
            
            ++d;
        }
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* tmp = node->left;
            node->left = new TreeNode(val, tmp, nullptr);
            tmp = node->right;
            node->right = new TreeNode(val, nullptr, tmp);
        }
        
        return root;
    }
};
