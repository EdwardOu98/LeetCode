#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // If input array is empty, return 0
        if(nums.empty()) {
            return 0;
        }
        // Build a hash-set with the elements in nums
        unordered_set<int> uset(nums.begin(), nums.end());
        int res = 1; // The minimum consecutive sequence length is 1

        while(!uset.empty()) {
            // Get the first element in the hash-set
            int curr = *uset.begin();
            // Erase the current number from hash-set to prevent repetitive
            // calculations
            uset.erase(curr);

            // Use the current number as the pivot to expand the consecutive
            // sequence
            int l = curr - 1, r = curr + 1;
            int count = 1;
            while(uset.count(l)) {
                ++count;
                uset.erase(l--);
            }

            while(uset.count(r)) {
                ++count;
                uset.erase(r++);
            }

            res = max(res, count);
        }

        return res;
    }
};
