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
    int sum;
    void dfs(TreeNode* root, int curr) {
        if(!root) {
            return;
        }
        // 计算到当前结点的数字
        curr = curr * 10 + root->val;
        // 如果当前结点为叶子结点，则将当前数字加到最终结果中
        if(!root->left && !root->right) {
            sum += curr;
            return;
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
    }
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};
