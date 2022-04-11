#include <set>

using namespace std;

class Solution {
private:
    bool slidingWindow(vector<int>& nums, int k, int t) {
        // 用long型避免溢出
        set<long> s;
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            long num = nums[i];

            // 确保哈希表表长不超过k
            if(i > k) {
                s.erase(nums[i - k - 1]);
            }

            // 找到表中第一个大小不小于num-t的数
            auto p = s.lower_bound(num - t);

            // 如果能找到一个大小不小于num-t的数且该数和当前数的差值也不超过t
            // 则返回true
            if((p != s.end()) && ((*p - num) <= t)) {
                return true;
            }
            s.insert(num);
        }

        return false;
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        return slidingWindow(nums, k, t);
    }
};
