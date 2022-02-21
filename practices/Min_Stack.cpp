#include <stack>

using namespace std;

class MinStack {
// 思路：用两个栈分别存储输入数据
// 和现有数据中的最小值。如果在调用
// pop()函数时会改变现有数据的最小值，
// 则在pop数据栈的同时pop最小值栈
private:
    stack<int> stk, minElem;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if(minElem.empty() || x <= min()) {
            minElem.push(x);
        }
    }
    
    void pop() {
        if(stk.top() == min()) {
            minElem.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return minElem.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
