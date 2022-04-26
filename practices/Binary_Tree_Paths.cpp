#include <string>
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
    vector<string> res;
    
    void dfs(TreeNode* root, string s) {
        if(!root) {
            return;
        }
        string num = to_string(root->val);
        if(!root->left && !root->right) {
            s += num;
            res.push_back(s);
            return;
        }
        
        dfs(root->left, s + num + "->");
        dfs(root->right, s + num + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return res;
    }
};
