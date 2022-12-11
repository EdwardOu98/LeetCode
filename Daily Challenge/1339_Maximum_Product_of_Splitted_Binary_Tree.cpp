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
    long total, res, sub;
    const int MOD = 1e9 + 7;

    int getSubSum(TreeNode* root) {
        if(!root) {
            return 0;
        }

        sub = root->val + getSubSum(root->left) + getSubSum(root->right);

        res = max(res, sub * (total - sub));

        return sub;
    }
public:
    int maxProduct(TreeNode* root) {
        total = getSubSum(root);
        getSubSum(root);

        return res % MOD;
    }
};
