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
        TreeNode* last = nullptr;
        TreeNode* temp;
        
        while(root || !s.empty()) {
            if(root) {
                s.push(root);
                root = root->left;
            }
            else {
                temp = s.top();
                if(temp->right && temp->right != last) {
                    root = temp->right;
                }
                else {
                    res.push_back(temp->val);
                    last = temp;
                    s.pop();
                }
            }
        }
    }
    
    void postorder(TreeNode* root) {
        if(!root) {
            return;
        }
        
        postorder(root->left);
        postorder(root->right);
        
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // postorder(root);
        iterative(root);
        
        return res;
    }
};
