#include <vector>
#include <stack>

using namespace std;

class StackOfPlates {
private:
    vector<stack<int>> stacks;
    int capacity;
public:
    StackOfPlates(int cap) {
        capacity = cap;
    }
    
    void push(int val) {
        // If the maximum capacity of the stacks is less than or equal
        // to 0, reject any push operation
        if(capacity <= 0) {
            return;
        }

        // If there are no stacks or the last stack is full, add a new
        // stack to the array
        if(stacks.empty() || stacks.back().size() >= capacity) {
            stacks.push_back(stack<int>());
        }

        // Add the new element to the last stack
        stacks.back().push(val);
    }
    
    // Pop operation is the same as normal stack
    int pop() {
        return popAt(stacks.size() - 1);
    }
    
    int popAt(int index) {
        // If the capacity of the stacks is 0, or the input index is
        // out of bound, return -1
        if(capacity <= 0 || index >= stacks.size() || index < 0) {
            return -1;
        }

        int val = stacks[index].top();
        stacks[index].pop();

        // If after the pop operation the indicated stack is empty, 
        // remove it from the array
        if(stacks[index].empty()) {
            stacks.erase(stacks.begin() + index);
        }

        return val;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
