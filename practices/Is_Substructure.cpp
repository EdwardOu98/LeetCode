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
// 思路：需要建一个辅助函数isSameTree用于判断
// 树B是否为树A的一个子结构。函数需要两个参数，
// 其中*p指向树A的结点，*q指向树B的结点。先判断
// p和q所指向位置是否为空。如果q为空，则说明先前
// 的所有比较都通过，树B是树A的子结构，故返回true。
// 如果p为空且q不为空，则说明树B和树A在这一部分的子
// 结构并不相同，故返回false。在判断返回值时，除比较
// 树A当前结点和树B当前结点的值是否相同外，还需查看
// 树A当前结点的左右子树和树B当前结点的左右子树是否
// 相同。而在主运行函数中，判断返回值时不仅要用树A和
// 树B进行比较，还需要用树A根结点的左右子树以及它们的
// 子树进行比较。因为树B可能和树A在任意位置上的子结构
// 重合。
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q) {
            return true;
        }
        if(!p) {
            return false;
        }
        
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) {
            return false;
        }

        return isSameTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
