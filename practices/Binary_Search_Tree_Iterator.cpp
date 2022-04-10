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
class BSTIterator {
private:
    stack<TreeNode*> stk;
public:
    // 将从输入结点开始往左的左单枝树压入栈中
    void place(TreeNode* root) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        place(root);
    }
    
    int next() {
        // 先取出当前在栈顶的结点
        TreeNode* ret = stk.top();
        stk.pop();
        // 将当前结点从右侧的左单枝树入栈
        place(ret->right);
        return ret->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
