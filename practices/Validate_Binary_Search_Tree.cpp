using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
// Basic idea: The inorder traversal of a BST will result in a
// increasing sequence. So we simply need to use inorder traversal
// to find whether there are any number that are not in the proper
// position
private:
    stack<TreeNode*> s;
    void place(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        place(root);

        // Record the previous element
        long prev = (long) INT_MIN - 1;

        while(!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            // If the current node's value is less than or equal
            // to the previous value, then the tree is invalid
            if(curr->val <= prev) {
                return false;
            }
            // Update the previous value and prepare the next node
            // to visit
            prev = curr->val;
            curr = curr->right;
            place(curr);
        }

        return true;
    }
};
