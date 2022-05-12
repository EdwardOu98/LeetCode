#include <stack>

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
private:
    stack<TreeNode*> s;

    void place(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) {
            return nullptr;
        }

        place(root);
        // TreeNode* prev = nullptr;

        while(!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            // Method 1: Find p and then its successor
            // if(prev && prev == p) {
            //     return curr;
            // }
            // prev = curr;
            
            // Method 2: Find the first node whose value is greater
            // than p's value
            if(curr->val > p->val) {
                return curr;
            }
            curr = curr->right;
            place(curr);
        }

        return nullptr;
    }
};
