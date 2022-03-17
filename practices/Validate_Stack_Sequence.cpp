#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    // 用指针模拟栈
    bool pointers(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, k = 0, n = pushed.size();

        // k为栈顶指针，从0到k为当前栈内元素；i为待入栈指针，
        // 从k到i为待入栈元素；j用来指示当前待出栈元素
        while(i < n) {
            pushed[k] = pushed[i];
            ++k;
            while(j < n && k > 0 && pushed[k-1] == popped[j]) {
                --k;
                ++j;
            }
            ++i;
        }

        return j == n;
    }
    // 用栈实际模拟压入弹出过程
    bool simulation(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0, n = popped.size();
        for(int x  : pushed) {
            stk.push(x);
            while(!stk.empty() && i < n && stk.top() == popped[i]) {
                stk.pop();
                ++i;
            }
        }

        return i == n;
    }
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // return simulation(pushed, popped);
        return pointers(pushed, popped);
    }
};
