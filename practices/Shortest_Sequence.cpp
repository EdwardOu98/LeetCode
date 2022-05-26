#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        vector<int> res;
        unordered_map<int, int> m; // number in small - count of this number
        int count = 0; // Count of distinct numbers in small
        int left = 0, right; // Left and right boundary

        for(int& n : small) {
            // If the current number is not in the hashmap yet, increment count
            // for distinct numbers
            if(!m[n]) {
                ++count;
            }
            ++m[n];
        }

        int len = big.size();

        for(right = 0; right < big.size(); ++right) {
            // Add one number to the sliding window
            --m[big[right]];
            // If the current number is in the small array
            // and it's the last one we need to include, decrement
            // the distinct number count
            if(!m[big[right]]) {
                --count;
            }

            // If we have included all the numbers from the small array
            while(!count) {
                // Remove one number from the sliding window
                ++m[big[left]];
                // If the removed number is in the small array, increment
                // the distinct number count, and update the window size
                if(m[big[left]] > 0) {
                    ++count;
                    if(res.empty() || res[1] - res[0] > right - left) {
                        res = {left, right};
                    }
                }
                ++left;
            }
        }

        return res;
    }
};
