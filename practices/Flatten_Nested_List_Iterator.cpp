#include <stack>
#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> nodes; // Stores the nodes in the nested list
    
    // nestedLisr - Input list
    // n - length of input list
    void placeNodes(vector<NestedInteger>& nestedList, int n) {
        for(int i = n - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Adding the nodes in the list to the stack backwards so that when
        // we access the nodes they are in the forward direction
        placeNodes(nestedList, nestedList.size());
    }
    
    int next() {
        // Get the element at the top of the stack
        int res = nodes.top().getInteger();
        // Remove the top element from the stack
        nodes.pop();
        // Return the element
        return res;
    }
    
    bool hasNext() {
        // The loop is valid only when the stack is not empty
        while(!nodes.empty()) {
            NestedInteger curr = nodes.top();
            
            // If the current top element is an integer, then we can directly
            // access its value in the next() function
            if(curr.isInteger()) {
                return true;
            }
            
            // If the current top element is another nested list, we need to
            // flatten it.
            vector<NestedInteger>& nestedList = curr.getList();
            // Remove the top element in the stack
            nodes.pop();
            // Add the new list nodes to the stack
            placeNodes(nestedList, nestedList.size());
        }
        
        // When the stack is empty, there's no next element in the nested list
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
