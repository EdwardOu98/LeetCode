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
    TreeNode* buildTree(vector<int>& post, vector<int>& in, int L1, int R1, int L2, int R2) {
        if(L1 > R1) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(post[R1]);
        int i;
        for(i = L2; i <= R2; ++i) {
            if(in[i] == post[R1]) {
                break;
            }
        }
        
        root->right = buildTree(post, in, L1 + i - L2, R1 - 1, i + 1, R2);
        root->left = buildTree(post, in, L1, L1 + i - L2 - 1, L2, i - 1);
        
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};
