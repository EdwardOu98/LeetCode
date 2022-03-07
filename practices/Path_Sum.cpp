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
    void backtracking(vector<vector<int>>& res, vector<int>& temp, TreeNode* root, int target) {
        if(!root) {
            return;
        }
        if(root->val == target && !root->left && !root->right) {
            temp.push_back(root->val);
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        if(root->left) {
            temp.push_back(root->val);
            backtracking(res, temp, root->left, target - root->val);
            temp.pop_back();
        }
        if(root->right) {
            temp.push_back(root->val);
            backtracking(res, temp, root->right, target - root->val);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        backtracking(res, temp, root, target);
        return res;
    }
};
