#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        // Sum up all elements in the 
        long long s = accumulate(target.begin(), target.end(), (long long) 0);
        // Use a priority queue to keep track of the maximum element in the array
        priority_queue<long long> pq(target.begin(), target.end());
        
        // If the largest element is smaller than or equal to s / 2, we can't continue
        while(s > 1 && pq.top() > s / 2) {
            long long curr = pq.top();
            pq.pop();
            s -= curr;
            // Handle special cases when s - curr == 1
            if(s <= 1) {
                return s;
            }
            // In the case where the largest element is significantly
            // larger than the sum of other elements, we can get TLE.
            // Use s % curr instead of s - curr
            pq.push(curr % s);
            s += curr % s;
        }
        
        // If we are able to construct the target array from an array of 1's, s
        // should be equal to the length of the target array
        return s == target.size();
    }
};
