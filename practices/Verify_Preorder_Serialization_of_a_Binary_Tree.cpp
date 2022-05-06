#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string val;
        int capacity = 1; // Total capacity of the tree. Initialized as 1
                          // for the root node
        
        while(getline(ss, val, ',')) {
            // If total number of nodes exceeds the capacity of the tree,
            // return false
            if(--capacity < 0) {
                return false;
            }
            
            // If the current node is not NULL, then it can create two more
            // leaves (capacity + 2)
            if(val != "#") {
                capacity += 2;
            }
        }
        
        // If the preeorder serialization is valid, the capacity should be
        // 0 after iterating through the whole string
        return capacity == 0;
    }
};
