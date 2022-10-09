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
    bool search(TreeNode* root, TreeNode* curr, int k) {
        if(!root) {
            return false;
        }
        
        return ((root->val == k) && (root != curr)) ||
               ((root->val < k) && (search(root->right, curr, k))) ||
               ((root->val > k) && (search(root->left, curr, k)));
    }
    
    bool dfs(TreeNode* root, TreeNode* curr, int k) {
        if(!curr) {
            return false;
        }
        
        return search(root, curr, k - curr->val) || dfs(root, curr->left, k) || 
               dfs(root, curr->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        
        return dfs(root, root, k);
    }
};
