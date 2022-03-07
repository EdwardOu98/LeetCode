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
    void RInorder(TreeNode* root, int& k, int& count, int& res) {
        if(!root || count >= k) {
            return;
        }
        RInorder(root->right, k, count, res);
        ++count;
        if(count == k) {
            res = root->val;
            return;
        }
        RInorder(root->left, k, count, res);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        int count = 0, res;
        RInorder(root, k, count, res);
        return res;
    }
};
