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
    int countNodes(TreeNode* root, int maxVal) {
        if(!root) {
            return 0;
        }
        
        int isGood = 0;
        
        if(root->val >= maxVal) {
            maxVal = root->val;
            isGood = 1;
        }
        
        return isGood + countNodes(root->left, maxVal) + countNodes(root->right, maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return countNodes(root, root->val);
    }
};
