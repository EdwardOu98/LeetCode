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
    TreeNode* prev = nullptr;
    TreeNode* newRoot = nullptr;
    void inorder(TreeNode* root) {
        // 如果输入结点为空则直接返回
        if(!root) {
            return;
        }
        // 先探索左子树
        inorder(root->left);
        // 如果prev指针为空(即当前为中序遍历中第一个访问的非空结点)
        // 则将其设为新的根结点
        if(!prev) {
            newRoot = root;
        }
        // 否则将当前结点的左指针置空，同时将上一个访问的结点
        // 的右指针指向当前结点
        else {
            root->left = nullptr;
            prev->right = root;
        }
        // 将prev设为当前结点
        prev = root;
        // 访问右子树
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return newRoot;
    }
};
