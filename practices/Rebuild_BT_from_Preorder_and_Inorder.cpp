#include <vector>
#include <algorithm> // std::find

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
    TreeNode* buildBT(vector<int>& preorder, vector<int>& inorder, int L1, int R1, int L2, int R2) {
        if(L1 > R1) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[L1]);

        int i = find(inorder.begin() + L2, inorder.begin() + R2, preorder[L1]) - inorder.begin();
        root->left = buildBT(preorder, inorder, L1 + 1, L1 + i - L2, L2, i - 1);
        root->right = buildBT(preorder, inorder, L1 + i - L2 + 1, R1, i + 1, R2);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildBT(preorder, inorder, 0, (preorder.size() - 1), 0, (inorder.size() - 1));
    }
};
