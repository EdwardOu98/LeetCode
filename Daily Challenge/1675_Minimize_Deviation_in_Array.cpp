#include <iostream>	// cout
#include <queue>	// priority_queue
#include <vector>	// vector

using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // To simplify the problem, we only perform 
        // one operation on the array elements at a time. Then we use a 
        // priority queue to keep track of the largest element (and make
        // sure it's even) and an int variable to keep track
        // of the minimum element so that we can know the maximum
        // deviation of the array. While the max element is even, we
        // remove it, halve it, and put it back. By doing so, when we meet
        // an odd maximum element, we know that it can't be smaller.
        // Then we just need to calculate the difference between the maximum
        // and minimum element to find the deviation
        int res = INT_MAX, min_element = INT_MAX;
        priority_queue<int> pq;
        
        for(int n : nums) {
            n = (n % 2) ? n * 2 : n;
            pq.push(n);
            min_element = min(n, min_element);
        }
        
        while(pq.top() % 2 == 0) {
            int tmp = pq.top();
            pq.pop();
            res = min(res, tmp - min_element);
            tmp /= 2;
            min_element = min(min_element, tmp);
            pq.push(tmp);
        }
        
        return min(res, pq.top() - min_element);
    }
};
