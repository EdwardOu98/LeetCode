#include <stack>

using namespace std;

class SortedStack {
private:
    stack<int> s1, s2;
public:
    SortedStack() {

    }
    
    void push(int val) {
        // If s1 is empty or the input value is less
        // than or equal to the top element of s1, 
        // directly add the input to s1.
        if(s1.empty() || val <= s1.top()) {
            s1.push(val);
        }
        // When the input value is greater than the top 
        // element of s1, continuously move the top element
        // of s1 to s2 until the current top is greater than
        // or equal to the input value. Add the input to s1,
        // then move the elements in s2 back to s1 
        else {
            while(!s1.empty() && s1.top() < val) {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(val);
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    void pop() {
        if(!s1.empty()) {
            s1.pop();
        }
    }
    
    int peek() {
        return s1.empty() ? -1 : s1.top();
    }
    
    bool isEmpty() {
        return s1.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
