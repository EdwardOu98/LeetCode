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
        // If any of the input nodes are NULL, return a null pointer
        if(!root || !p || !q) {
            return nullptr;
        }
        
        // If both p and q are on the left side of the root, search for their
        // LCA in the left subtree
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // If both p and q are on the right side of the root, search for their
        // LCA in the right subtree
        if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // Otherwise, return root
        return root;
    }
};
