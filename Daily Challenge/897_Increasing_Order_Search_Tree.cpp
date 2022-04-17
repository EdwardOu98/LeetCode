#include <stack>

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
    TreeNode* newRoot = NULL;

    void inorderTraverse(TreeNode* root) {
        if(!root) {
            return;
        }
        
        inorderTraverse(root->left);
        if(!prev) {
            newRoot = root;
            prev = root;
        }
        else {
            root->left = NULL;
            prev->right = root;
            prev = root;
        }
        
        inorderTraverse(root->right);
    }
    
    void iterative(TreeNode* root) {
        if(!root) {
            return;
        }
        
        stack<TreeNode*> s;
        
        while(root) {
            s.push(root);
            root = root->left;
        }
        
        while(!s.empty()) {
            root = s.top();
            s.pop();
            if(!prev) {
                newRoot = root;
                prev = root;
            }
            else {
                root->left = NULL;
                prev->right = root;
                prev = root;
            }
            
            root = root->right;
            while(root) {
                s.push(root);
                root = root->left;
            }
        }
        
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inorderTraverse(root);
        // iterative(root);
        
        return newRoot;
    }
};
