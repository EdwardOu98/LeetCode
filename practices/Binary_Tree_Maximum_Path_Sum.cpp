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
    // 求路径的最大和
    int getMax(TreeNode* root, int& m) {
        if(!root) {
            return 0;
        }

        int left = getMax(root->left, m); // 求左子树中最大路径和
        int right = getMax(root->right, m); // 求右子树中最大路径和

        // 对于当前结点的最大路径和可能是结点值本身(左右子树最大路径和均为负)或
        // 左右子树最大路径和中的较大者加上当前结点本身
        int currMax = max(root->val, max(left, right) + root->val);
        // 对于整棵树的最大路径和可能是当前结点的最大路径和、左右子树最大路径和
        // 加上当前结点自身、或先前已经计算出的最大路径和
        m = max(m, max(currMax, left + right + root->val));
        return currMax;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int m = INT_MIN;
        getMax(root, m);
        return m;
    }
};
