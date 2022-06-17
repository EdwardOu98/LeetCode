#include <unordered_set>

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
    int res;
    unordered_set<TreeNode*> covered;
    
    void dfs(TreeNode* root, TreeNode* parent) {
        // If root exists
        if(root) {
            // Try to add a camera in its left and right subtree
            dfs(root->left, root);
            dfs(root->right, root);
            
            // If the current node doesn't have a parent node and it's
            // not covered by any camera, or its left or right child is
            // not covered by any camera, we put a camera at the current
            // node
            if((!parent && !covered.count(root)) || !covered.count(root->left) ||
               !covered.count(root->right)) {
                ++res;
                covered.insert(root);
                covered.insert(parent);
                covered.insert(root->left);
                covered.insert(root->right);
            }
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        covered.insert(nullptr);
        dfs(root, nullptr);
        
        return res;
    }
};
