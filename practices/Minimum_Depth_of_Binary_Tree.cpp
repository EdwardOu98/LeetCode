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
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int n, i;
        int level = 0;
        bool flag = false;
        TreeNode* p;
        
        while(!q.empty() && !flag) {
            n = q.size();
            for(i = 0; i < n; ++i) {
                p = q.front();
                q.pop();
                
                if(!p->left && !p->right) {
                    flag = true;
                    break;
                }
                if(p->left) {
                    q.push(p->left);
                }
                
                if(p->right) {
                    q.push(p->right);
                }
            }
            ++level;
        }
        
        return level;
    }
};
