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
    int sum = 0, l, h;
    
    void traverse(TreeNode* root) {
        if(!root) {
            return;
        }
        
        if(root->val >= l && root->val <= h) {
            sum += root->val;
        }
        
        traverse(root->left);
        traverse(root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) {
            return 0;
        }
        
        l = low, h = high;
        traverse(root);
        return sum;
    }
};
