#include <unordered_map>
#include <stack>

using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freq; // count the occurence of each element
    unordered_map<int, stack<int>> group; // map from frequency to a stack of that frequency
    int maxFreq; // maximum frequency
public:
    FreqStack() {
        maxFreq = 0; // Initialize maxFreq to 0
    }
    
    void push(int val) {
        int f = ++freq[val]; // Increment frequency of val
        maxFreq = max(maxFreq, f); // Update maxFreq
        group[f].push(val); // push val into the stack of frequency f
    }
    
    int pop() {
        int x = group[maxFreq].top(); // get the top element from the stack with maximum frequency
        group[maxFreq].pop();
        --freq[x];  // decrement frequency of that element
        
        // if the stack is empty, decrement maxFreq as there's no more element with the current maxFreq
        if(group[maxFreq].empty()) {
            --maxFreq;
        }
        
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
