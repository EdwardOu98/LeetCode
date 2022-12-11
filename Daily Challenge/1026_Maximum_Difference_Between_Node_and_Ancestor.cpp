#include <algorithm>

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
    int findMinMax(TreeNode* root, int currMax, int currMin) {
        if(!root) {
            return currMax - currMin;
        }
        
        currMax = max(currMax, root->val);
        currMin = min(currMin, root->val);
        int left = findMinMax(root->left, currMax, currMin);
        int right = findMinMax(root->right, currMax, currMin);
        return max(left, right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        return findMinMax(root, root->val, root->val);
    }
};
