#include <vector>

using namespace std;

class Solution {
private:
    bool verify(vector<int>& postorder, int left, int right) {
        // 如果当前区域长度小于等于0，则说明这一部分只有一个或没有节点，直接返回true
        if(left >= right) {
            return true;
        }

        // 下标为right的数字对应当前的根结点
        int rootVal = postorder[right]; // 记录根值
        int k = left;

        // 从左向右扫描数组，找到第一个大于根值的数字的下标。从left到这个下标的前一个
        // 位置是当前结点的左子树，从这个下标到right - 1是当前结点的右子树。
        while(k < right && postorder[k] < rootVal) {
            ++k;
        }

        // 判断右子树中是否存在小于根结点的数，如果有则返回false
        for(int i = k; i < right; ++i) {
            if(postorder[i] < rootVal) {
                return false;
            }
        }

        // 如果当前树没问题则检查左右子树
        return (verify(postorder, left, k - 1) && verify(postorder, k, right - 1)) ? true : false;
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if(n < 2) {
            return true;
        }
        return verify(postorder, 0, n - 1);
    }
};
