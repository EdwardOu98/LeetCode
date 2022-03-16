#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    // 时间复杂度O(n)，空间复杂度O(n)
    bool simulation(vector<int>& pushed, vector<int>& popped) {
        int N = pushed.size();
        stack<int> stk;
        int j = 0;
        
        // 将pushed数组中的数字依次压入栈中，然后尝试根据popped队列中的顺序
        // 出栈。如果popped队列的顺序可行，则最终j应等于N。
        for(int x : pushed) {
            stk.push(x);
            while(!stk.empty() && j < N && stk.top() == popped[j]) {
                stk.pop();
                ++j;
            }
        }
        
        return j == N;
    }
    
    // 时间复杂度O(n)，空间复杂度O(1)
    bool pointers(vector<int>& pushed, vector<int>& popped) {
        int N = pushed.size();
        int i = 0, j = 0, k = 0;
        
        while(i < N) {
            pushed[k] = pushed[i];
            ++k;
            while(j < N && k > 0 && popped[j] == pushed[k-1]) {
                ++j;
                --k;
            }
            ++i;
        }
        
        return j == N;
    }
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        return pointers(pushed, popped);
    }
};
