#include <vector>
#include <queue>

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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            double sum = 0.0;
            double n = q.size();
            for(int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                sum += root->val;
                if(root->left) {
                    q.push(root->left);
                }
                if(root->right) {
                    q.push(root->right);
                }
            }
            res.push_back(sum / n);
        }
        
        return res;
    }
};
