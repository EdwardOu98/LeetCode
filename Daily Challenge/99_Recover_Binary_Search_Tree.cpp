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
// Idea: use inorder traversal to find the two mistaken nodes and then swap their value;
private:
    TreeNode* prev = nullptr;
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    
    void inorder(TreeNode* root) {
        if(!root) {
            return;
        }
        
        inorder(root->left);
        
        if(prev && !node1 && prev->val >= root->val) {
            node1 = prev;
        }
        
        if(node1 && prev->val >= root->val) {
            node2 = root;
        }
        
        prev = root;
        
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(node1 && node2) {
            swap(node1->val, node2->val);
        }
    }
};
