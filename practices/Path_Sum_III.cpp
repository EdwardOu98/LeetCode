#include <unordered_map>

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
// 思路：dfs+前缀和
private: 
    int paths = 0;
    int target;
    unordered_map<int, int> prefixSum;
    void dfs(TreeNode* root, int sum) {
        if(!root) {
            return;
        }
        // 计算当前路径(从根结点到当前结点)的前缀和(包括当前结点自身)，如果
        // 当前前缀和和目标和的差值在哈希表中出现过，则说明该差值的出现次数
        // 就是符合条件的序列的出现次数
        sum += root->val;
        if(prefixSum[sum - target]) {
            paths += prefixSum[sum - target];
        }
        // 将当前结点的前缀和出现次数加1
        ++prefixSum[sum];
        // 探索左右子树
        dfs(root->left, sum);
        dfs(root->right, sum);
        // 将当前结点的前缀和出现次数减1(向上返回)
        --prefixSum[sum];
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root) {
            target = targetSum;
            prefixSum[0] = 1;
            dfs(root, 0);
        }
        return paths;
    }
};
