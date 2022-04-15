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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // If root is empty, return
        if(!root) {
            return root;
        }
        
        // If root->val > high, then all the nodes on its right
        // subtree must be larger than high. Thus, we can drop
        // the root and its right subtree and return its trimmed
        // left child as the new root;
        if(root->val > high) {
            return trimBST(root->left, low, high);
        }
        
        // Similarly, if root->val < low, then all the nodes on its
        // left subtree must be smaller than low. Thus, we can drop
        // the root and its left subtree and return its trimmed right
        // child as the new root;
        if(root->val < low) {
            return trimBST(root->right, low, high);
        }
        
        // Otherwise, we trim the root's left and right subtree and
        // return root
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};
