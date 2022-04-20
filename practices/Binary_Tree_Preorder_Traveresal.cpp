#include <vector>
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
    vector<int> res;
    
    void iterative(TreeNode* root) {
        stack<TreeNode*> s;
        
        while(root || !s.empty()) {
            if(root) {
                res.push_back(root->val);
                if(root->right) {
                    s.push(root->right);
                }
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
            }
        }
    }
    
    void preorder(TreeNode* root) {
        if(!root) {
            return;
        }
        
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // preorder(root);
        iterative(root);
        
        return res;
    }
};
