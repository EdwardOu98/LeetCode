using namespce std;

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
private:
    bool flag = true;
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        if(abs(leftDepth - rightDepth) > 1) {
            flag = false;
        }

        return 1 + max(leftDepth, rightDepth);
    }
public:
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return flag;
    }
};
