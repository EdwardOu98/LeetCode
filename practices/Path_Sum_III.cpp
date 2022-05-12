#include <unordered_map>

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
    int totalPaths = 0;
    int target;
    unordered_map<int, int> prefixSum;

    void dfs(TreeNode* root, int sum) {
        // When we see an empty node, return to the previous level
        if(!root) {
            return;
        }

        sum += root->val;
        // If we have seen the difference beween the current sum and
        // the target before, then the number of sequence that meets
        // the requirement is equal to the times this difference
        // occurred before
        if(prefixSum[sum - target]) {
            totalPaths += prefixSum[sum - target];
        }

        // Increment the count of the current prefix sum
        ++prefixSum[sum];

        // Visit the left and right subtree
        dfs(root->left, sum);
        dfs(root->right, sum);

        // Decrement the count of the current prefix sum
        // and return to the previous level
        --prefixSum[sum];
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root) {
            target = sum;
            prefixSum[0] = 1;
            dfs(root, 0);
        }
        return totalPaths;
    }
};
