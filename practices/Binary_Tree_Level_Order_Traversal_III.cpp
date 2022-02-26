#include <algorithm>
#include <vector>
#include <queue>

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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }

        queue<TreeNode*> q;
        vector<vector<int>> res;
        int direction = 0;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;

            for(int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }

                temp.push_back(curr->val);
            }
            if(direction) {
                reverse(temp.begin(), temp.end());
            }
            
            res.push_back(temp);

            direction = ~direction;
        }

        return res;
    }
};
