#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int num : nums) {
            // Add one element to the priority queue
            pq.push(num);
            // If the queue size is too big, remove one
            // element from the queue
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // After iterating through the entire array, the 
        // top element of the priority queue is the element
        // we are looking for
        return pq.top();
    }
};
