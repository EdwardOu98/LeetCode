#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        // 时间点最多有24 * 60个，因此如果输入数组的长度超过这个值，则说明一定
        // 有重复时间点，可以直接返回0
        if(n > 24 * 60) {
            return 0;
        }

        // 将传入的所有时间点转变成分钟制，即将小时数乘以60再加上分钟数
        vector<int> minutes;
        for(string& t : timePoints) {
            minutes.push_back(stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3)));
        }

        // 对转换后的数组进行排序
        sort(minutes.begin(), minutes.end());
        // 将最小的分钟数加上24 * 60用于处理最大值和最小值的差值的特殊情况
        minutes.push_back(minutes[0] + 24 * 60);
        // 差值最大为24 * 60
        int res = 24 * 60;
        for(int i = 1; i <= n; ++i) {
            res = min(res, minutes[i] - minutes[i-1]);
        }
        return res;
    }
};
