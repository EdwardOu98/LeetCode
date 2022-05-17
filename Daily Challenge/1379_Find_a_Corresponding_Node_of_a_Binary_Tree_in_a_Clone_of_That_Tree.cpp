#include <queue>
#include <stack>

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
    TreeNode* BFSSolution(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q1, q2;
        q1.push(original);
        q2.push(cloned);
        
        while(!q1.empty() && !q2.empty()) {
            TreeNode* n1 = q1.front();
            q1.pop();
            TreeNode* n2 = q2.front();
            q2.pop();
            
            if(n1 == target) {
                return n2;
            }
            
            if(n1->left) {
                q1.push(n1->left);
            }
            if(n1->right) {
                q1.push(n1->right);
            }
            
            if(n2->left) {
                q2.push(n2->left);
            }
            if(n2->right) {
                q2.push(n2->right);
            }
        }
        
        return nullptr;
    }
    
    TreeNode* iterativePreorderTraversal(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> s1, s2;
        TreeNode* o = original, *c = cloned;
        
        while(!s1.empty() || o) {
            if(o) {
                if(o == target) {
                    return c;
                }
                if(o->right) {
                    s1.push(o->right);
                    s2.push(c->right);
                }
                o = o->left;
                c = c->left;
            }
            else {
                o = s1.top();
                s1.pop();
                c = s2.top();
                s2.pop();
            }
        }
        
        return nullptr;
    }
    
    TreeNode* res = nullptr;
    TreeNode* target;
    
    void recursivePreorder(TreeNode* o, TreeNode* c) {
        if(!res && o) {
            if(o == target) {
                res = c;
                return;
            }
            recursivePreorder(o->left, c->left);
            recursivePreorder(o->right, c->right);
        }
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this->target = target;
        recursivePreorder(original, cloned);
        return res;
    }
};
