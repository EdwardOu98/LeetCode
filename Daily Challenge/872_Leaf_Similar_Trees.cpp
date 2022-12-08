#include <vector>

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
    void preorder(TreeNode* root, vector<int>& l) {
        if(!root) {
            return;
        }

        if(!root->left && !root->right) {
            l.push_back(root->val);
        }

        preorder(root->left, l);
        preorder(root->right, l);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> la, lb;
        preorder(root1, la);
        preorder(root2, lb);

        return la == lb;
    }
};
