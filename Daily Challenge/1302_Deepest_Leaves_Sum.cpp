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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int res = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        
        // Level order traversal
        while(!q.empty()) {
            // When we get down 1 level, we overwrite the result of
            // the previous level
            res = 0;
            for(int i = q.size(); i > 0; --i) {
                TreeNode* curr = q.front();
                q.pop();
                res += curr->val;
                
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
        }
        
        
        return res;
    }
};
