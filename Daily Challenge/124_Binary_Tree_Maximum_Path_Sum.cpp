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
    int maxSum = INT_MIN;
    
    int findMaxSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        // Find the maximum path sum on the left subtree
        int l = findMaxSum(root->left);
        
        // Find the maximum path sum on the right subtree
        int r = findMaxSum(root->right);
        
        // The current maximum path sum is root->val (if both the left
        // and right path sum is less than 0) or the maximum between left
        // and right path sum + root->val
        int currMax = max(root->val, root->val + max(l, r));
        
        // The final maximum path sum is the current maximum path sum, 
        // the sum of root->val and left and right path sum, or it has
        //  been calculated before
        maxSum = max({maxSum, currMax, root->val + l + r});
        
        // root->val + left path sum + right path sum should not be included
        // in the return value
        return currMax;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        findMaxSum(root);
        return maxSum;
    }
};
