#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }

        queue<TreeNode*> q;
        vector<int> res;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                res.push_back(curr->val);
            }
        }

        return res;
    }
};
