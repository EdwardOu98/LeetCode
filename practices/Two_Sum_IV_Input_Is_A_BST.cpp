#include <unordered_set>
#include <stack>

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
    unordered_set<int> uset;

    // 思路1：递归先序遍历+哈希表
    bool recurrsion(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        // 如果表中存在当前结点的值，则说明树中存在和为k的两个结点，返回true
        if(uset.count(root->val)) {
            return true;
        }

        // 将k-当前结点值的结果加入表中
        uset.insert(k - root->val);

        // 到左右子树中找与当前结点和为k的结点
        return recurrsion(root->left, k) || recurrsion(root->right, k);
    }

    // 思路2：非递归中序遍历+哈希表
    bool iteration(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(!stk.empty() || curr) {
            while(curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if(uset.count(curr->val)) {
                return true;
            }
            uset.insert(k - curr->val);
            curr = curr->right;
        }

        return false;
    }

    // 思路3：对左子树进行中序遍历，对右子树进行逆中序遍历从而获得树中当前未输出的最大
    // 和最小的值，将两者相加的结果和目标值进行比较。
    stack<TreeNode*> lstk, rstk;
    TreeNode *lCurr, *rCurr;

    // 对左子树进行中序遍历(LNR)
    int leftInorder() {
        while(lCurr) {
            lstk.push(lCurr);
            lCurr = lCurr->left;
        }
        lCurr = lstk.top();
        lstk.pop();
        int ret = lCurr->val;
        lCurr = lCurr->right;
        return ret;
    }

    // 对右子树进行逆中序遍历(RNL)
    int rightInorder() {
        while(rCurr) {
            rstk.push(rCurr);
            rCurr = rCurr->right;
        }
        rCurr = rstk.top();
        rstk.pop();
        int ret = rCurr->val;
        rCurr = rCurr->left;
        return ret;
    }

    bool twoPointers(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        lCurr = root, rCurr = root;
        int l = leftInorder(), r = rightInorder();

        while(l < r) {
            if(l + r == k) {
                return true;
            }
            else if(l + r < k) {
                l = leftInorder();
            }
            else {
                r = rightInorder();
            }
        }

        return false;
    }

public:
    bool findTarget(TreeNode* root, int k) {
        // return iteration(root, k);
        return twoPointers(root, k);
    }
};
