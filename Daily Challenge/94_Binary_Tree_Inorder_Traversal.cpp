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
    
    void recurrsive(TreeNode* root) {
        if(!root) {
            return;
        }
        recurrsive(root->left);
        res.push_back(root->val);
        recurrsive(root->right);
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
            
            res.push_back(root->val);
            
            root = root->right;
            
            while(root) {
                s.push(root);
                root = root->left;
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // recurrsive(root);
        iterative(root);
        
        return res;
    }
};
