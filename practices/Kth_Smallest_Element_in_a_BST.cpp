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
// idea: use inorder traversal, the kth visited node is the result we want
private:
    void place(stack<TreeNode*>& s, TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        
         place(s, root);
        
        while(!s.empty()) {
            root = s.top();
            s.pop();
            if(--k == 0) {
                return root->val;
            }
            root = root->right;
            place(s, root);
        }
        
        return 0;
    }
};
