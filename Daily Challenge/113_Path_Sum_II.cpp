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
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(TreeNode* root, int targetSum) {
        if(!root) {
            return;
        }
        if(root->val == targetSum && !root->left && !root->right) {
            temp.push_back(root->val);
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        
        if(root->left) {
            temp.push_back(root->val);
            dfs(root->left, targetSum - root->val);
            temp.pop_back();
        }
        
        if(root->right) {
            temp.push_back(root->val);
            dfs(root->right, targetSum - root->val);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        
        return res;
    }
};
