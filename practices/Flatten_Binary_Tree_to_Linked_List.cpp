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
private:
    TreeNode* prev = NULL;
    void preorder(TreeNode* root) {
        if(!root) {
            return;
        }
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(!prev) {
            prev = root;
        }
        else {
            prev->left = NULL;
            prev->right = root;
            prev = root;
        }
        
        preorder(left);
        preorder(right);
    }
public:
    void flatten(TreeNode* root) {
        preorder(root);
    }
};
