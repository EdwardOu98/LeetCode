#include <vector>

using namespacee std;

class Solution {
// 思路：采用滑动窗口。窗口中能取的最大值为target/2+1。    
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int j = 1, sum = 0, mid = target / 2 + 1;
        for(int i = 1; i <= mid; ++i) {
            sum += i;
            // 如果当前窗口和过大，则缩小窗口直到和小于等于目标
            while(sum > target) {
                sum -= j;
                ++j;
            }
            // 如果和为target，则将当前窗口加入返回数组
            if(sum == target) {
                vector<int> temp;
                for(int k = j; k <= i; ++k) {
                    temp.push_back(k);
                }
                res.push_back(temp);
            }
        }

        return res;
    }
};
