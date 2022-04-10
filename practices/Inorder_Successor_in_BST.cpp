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
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL;
        int target = p->val;
        while(root) {
            // 如果当前结点的值大于目标值，则说明目标值在当前结点的左侧
            // 且当前结点可能为目标结点的中序后继
            if(root->val > target) {
                res = root;
                root = root->left;
            }
            // 如果当前结点的值小于等于目标值，则说明后继在当前结点的右侧
            // 应向右移动
            else {
                root = root->right;
            }
        }

        return res;
    }
};
