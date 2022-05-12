#include <vector>

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
// Basic idea: Find the median in the array and make it the root
// of the BST. Then recursively build the left and right subtree
// with the same rule. 
private:
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        // Base case 1: When the current section of the array contains
        // 0 element, return a null node
        if(left > right) {
            return nullptr;
        }

        // Base case 2: When the current section of the array contains
        // only 1 element, build a node with the element and return the
        // node
        if(left == right) {
            return new TreeNode(nums[left]);
        }

        // Find the median of the current section of the input array
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtree
        root->left = buildTree(nums, left, mid - 1);
        root->right = buildTree(nums, mid + 1, right);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
