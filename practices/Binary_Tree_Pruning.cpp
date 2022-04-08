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
// 思路：后序遍历整棵二叉树，先对左右子树进行剪枝，再判断当前结点
// 是否已经是叶子结点。如果是叶子结点且值为0，则将当前结点从树中
// 移除。
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(!root->left && !root->right && root->val == 0) {
            return nullptr;
        }

        return root;
    }
};
