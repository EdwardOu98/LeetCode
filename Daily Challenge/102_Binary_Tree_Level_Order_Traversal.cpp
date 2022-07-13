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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        int n, i;
        TreeNode* p;
        while(!q.empty()) {
            n = q.size();
            vector<int> temp;
            for(i = 0; i < n; ++i) {
                p = q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left) {
                    q.push(p->left);
                }
                if(p->right) {
                    q.push(p->right);
                }
            }
            
            res.push_back(temp);
        }
        
        
        return res;
    }
};
