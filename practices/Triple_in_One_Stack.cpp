#include <vector>

using namespace std;

class TripleInOne {
private:
    vector<int> stk;
    int stackSize;
    int tops[3] = {0, 1, 2};
    /*
     * Stack arrangements:
     * Stack 1: 0, 0 + 3, 3 + 3, 6 + 3, ..., stackSize - 3
     * Stack 2: 1, 1 + 3, 4 + 3, 7 + 3, ..., stackSize - 2
     * Stack 3: 2, 2 + 3, 5 + 3, 8 + 3, ..., stackSize - 1
     */
public:
    TripleInOne(int stackSize) {
        this->stackSize = stackSize;
        stk.resize(3 * stackSize);
    }
    
    void push(int stackNum, int value) {
        // If the stack is full, reject the push operation
        if(tops[stackNum] >= 3 * stackSize) {
            return;
        }
        stk[tops[stackNum]] = value;
        tops[stackNum] += 3;
    }
    
    int pop(int stackNum) {
        if(isEmpty(stackNum)) {
            return -1;
        }
        tops[stackNum] -= 3;
        return stk[tops[stackNum]];
    }
    
    int peek(int stackNum) {
        if(isEmpty(stackNum)) {
            return -1;
        }
        return stk[tops[stackNum] - 3];
    }
    
    bool isEmpty(int stackNum) {
        return tops[stackNum] == stackNum;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
