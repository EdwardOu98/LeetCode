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
private:
    TreeNode* newRoot = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if(!root) {
            return;
        }

        inorder(root->left);
        if(!prev) {
            newRoot = root;
        }
        else{
            root->left = NULL;
            prev->right = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    TreeNode* convertBiNode(TreeNode* root) {
        inorder(root);
        return newRoot;
    }
};
