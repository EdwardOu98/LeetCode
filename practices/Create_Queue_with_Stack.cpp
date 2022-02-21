#include <stack>

using namespace std;

class CQueue {
// Stack: LIFO
// Queue: FIFO
// 思路：用一个栈堆stk1存储输入，另一个栈堆stk2存储输出数据
// 当stk2为空时，把stk1中的数据压入stk2中。因为栈堆是LIFO，
// 把stk1中的数据为输入数据的逆向，把stk1中的数据压入stk2中
// 就能还原输入的正确顺序。
private:
    stack<int> stk1, stk2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        
        if(!stk2.empty()) {
            int res = stk2.top();
            stk2.pop();
            return res;
        }
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
