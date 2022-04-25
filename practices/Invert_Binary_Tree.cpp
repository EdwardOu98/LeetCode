#include <queue>

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
    TreeNode* recurrsive(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        
        return root;
    }
    
    TreeNode* iterative(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* temp, *left;
        q.push(root);
        
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            left = temp->left;
            temp->left = temp->right;
            temp->right = left;
            
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
        
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        
        // return iterative(root);
        return recurrsive(root);
    }
};
