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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }
        else if((p && !q) || (!p && q)) {
            return false;
        }
        
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        
        return isSameTree(root->left, root->right);
    }
};
