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
    bool balanced = true;

    // Calculate the maximum height of the subtree whose root
    // node is the input root
    int maxHeight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int leftH = maxHeight(root->left);
        int rightH = maxHeight(root->right);
        // If the depth difference between the left and right
        // subtree is greater than 1, the tree is unbalanced
        if(abs(leftH - rightH) > 1) {
            balanced = false;
        }

        return 1 + max(leftH, rightH);
    }
public:
    bool isBalanced(TreeNode* root) {
        maxHeight(root);
        return balanced;
    }
};
