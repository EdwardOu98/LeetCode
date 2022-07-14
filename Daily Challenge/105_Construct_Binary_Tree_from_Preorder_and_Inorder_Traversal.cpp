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
    int N;
    TreeNode* buildTree(vector<int>& pre, vector<int>& in, int L1, int R1, int L2, int R2) {
        // If the current list contains 0 nodes, return a null pointer
        if(L1 > R1) {
            return nullptr;
        }
        
        // The root of the tree is the left-most number in the preorder sequence
        TreeNode* root = new TreeNode(pre[L1]);
        // Find the root number in the inorder sequence
        int i;
        for(i = L2; i <= R2; ++i) {
            if(in[i] == pre[L1]) {
                break;
            }
        }
        
        // Construct the left and right subtree
        root->left = buildTree(pre, in, L1 + 1, L1 + i - L2, L2, i - 1);
        root->right = buildTree(pre, in, L1 + i - L2 + 1, R1, i + 1, R2);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        N = preorder.size();
        return buildTree(preorder, inorder, 0, N - 1, 0, N - 1);
    }
};
