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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the root is null or it's either of p or q, return root
        if(!root || root == p || root == q) {
            return root;
        }
        
        // Try to find the lowest common ancestor in the left and
        // right subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If left is null, we return the right node. If right is null
        // we return the left node. If both are null, return root
        return !left ? right : (!right ? left : root);
    }
};
