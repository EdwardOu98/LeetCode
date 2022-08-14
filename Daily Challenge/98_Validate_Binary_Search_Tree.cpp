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
// Idea: use inorder traversal. If the previous node's value
// is greater than or equal to the current node's value, return
// false
private:
    TreeNode* prev = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return true;
        }
        
        if(!isValidBST(root->left)) {
            return false;
        }
        
        if(prev && prev->val >= root->val) {
            return false;
        }
        
        prev = root;
        
        return isValidBST(root->right);
    }
};
