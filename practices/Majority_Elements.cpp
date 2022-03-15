#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // 思路1:使用哈希表。时间复杂度和空间复杂度都为O(n)
    int usingHashTable(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int& num : nums) {
            ++m[num];
            if(m[num] > n / 2) {
                return num;
            }
        }

        return 0;
    }

    // 思路2:摩尔投票算法，时间复杂度为O(n)，空间复杂度为O(1)
    int BoyerMooreMajorityVote(vector<int>& nums) {
        int res = 0, count = 0;

        for(int& num : nums) {
            if(count == 0) {
                res = num;
                ++count;
            }
            else {
                (res == num) ? ++count : --count;
            }
        }

        return res;
    }
public:
    int majorityElement(vector<int>& nums) {
        // return usingHashTable(nums);
        return BoyerMooreMajorityVote(nums);
    }
};
