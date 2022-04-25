#include <queue>

using namespace std;

// Two queues solution
class MyStack {
private:
    queue<int> q1, q2;
    int topEle;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        // Add element to the queue
        // and update the top element
        topEle = x;
        q1.push(x);
    }
    
    int pop() {
        int ret = topEle;
        int n = q1.size();
        for(int i = 0; i < n; ++i) {
            // Move q1's element to q2
            // until the last one
            if(i != n - 1) {
                q2.push(q1.front());
            }
            // If the current element is
            // the second to last element,
            // set it as the new top element
            if(i == n - 2) {
                topEle = q1.front();
            }
            
            // Remove the current element 
            q1.pop();
        }
        
        // Add the elements back to q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
        return ret;
    }
    
    int top() {
        return topEle;
    }
    
    bool empty() {
        return q1.empty();
    }
};

// Single queue solution
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        // If, after pushing x into the queue, it contains
        // n elements, move the n - 1 elements in the front
        // to the back of the queue
        for(int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
