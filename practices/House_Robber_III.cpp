#include <algorithm>

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
    int rob(TreeNode* root, int& left, int& right) {
        // If the node is empty, return 0
        if(!root) {
            return 0;
        }
        
        int leftL = 0, leftR = 0, rightL = 0, rightR = 0;
        left = rob(root->left, leftL, leftR);
        right = rob(root->right, rightL, rightR);
        
        // The maximum amount robbed is either the sum of the current node and
        // its grandchildren's value, or the sum of the maximum amount that can
        // be robbed starting from its left and right child
        return max(root->val + leftL + leftR + rightL + rightR, left + right);
    }
public:
    int rob(TreeNode* root) {
        int left = 0, right = 0;
        return rob(root, left, right);
    }
};
