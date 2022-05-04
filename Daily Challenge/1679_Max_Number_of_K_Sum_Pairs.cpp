#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int res = 0;
        for(int num : nums) {
            // If we find a pair whose sum is k, increment
            // the pair count and decrement the count of 
            // the other element
            if(umap[k - num] > 0) {
                ++res;
                --umap[k-num];
            }
            // If we can't find a number to form a k-sum pair,
            // increment the count of the current number
            else {
                ++umap[num];
            }
        }
            
        return res;
    }
};
