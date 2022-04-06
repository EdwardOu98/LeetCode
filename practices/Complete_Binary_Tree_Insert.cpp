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
class CBTInserter {
private:
    TreeNode* root;     // 保存树的根结点
    queue<TreeNode*> q; // 用于保存可以插入新结点的结点
public:
    CBTInserter(TreeNode* _root) {
        root = _root;
        queue<TreeNode*> tempQ; 
        tempQ.push(_root);

        // 通过层序遍历找到所有下面可以插入新结点的结点并按序
        // 加入队列q中
        while(!tempQ.empty()) {
            int n = tempQ.size();
            for(int i = 0; i < n; ++i) {
                // 如果一个结点没有右孩子，则说明这个结点下面一定可以插入新结点
                if(!tempQ.front()->right) {
                    q.push(tempQ.front());
                }
                if(tempQ.front()->left) {
                    tempQ.push(tempQ.front()->left);
                }
                if(tempQ.front()->right) {
                    tempQ.push(tempQ.front()->right);
                }
                tempQ.pop();
            }
        }
    }
    
    int insert(int v) {
        int parent = q.front()->val;
        TreeNode* node = new TreeNode(v);
        // 如果当前可插入结点没有左孩子，则将新结点挂在左孩子上
        if(!q.front()->left) {
            q.front()->left = node;
        }
        // 如果当前可插入结点有左孩子但没有右孩子，则将新结点
        // 挂在右孩子上。同时因为当前结点的左右孩子都不为空，
        // 无法再接收新的结点，所以将当前结点出队
        else {
            q.front()->right = node;
            q.pop();
        }
        // 将新结点加入队列中
        q.push(node);
        return parent;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
