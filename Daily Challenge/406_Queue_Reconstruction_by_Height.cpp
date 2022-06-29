#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Sort the array with the following rule:
    // - If the two people have same height, the one with less people higher
    //   than him should go first in the queue
    // - If the two people have different height, the taller one should go first
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> queue; // The result queue
        queue.reserve(people.size()); // Reserve memory space for the queue
        
        for(auto& p : people) {
            queue.insert(queue.begin() + p[1], p);
        }
        
        return queue;
    }
};
