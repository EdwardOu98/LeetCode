#include <vector>
#include <algorithm>

using namespace std;

class Solution {
// 思路：用二分查找找出最小的速度。初始下界为1(因为速度最少需要为1)，上界为最大的一堆香蕉的数量
// (在这个速度下狒狒每小时只吃一堆，即使大于这个数也不会变)。求出中值之后计算吃完所有香蕉所需的
// 时间，计算方式为用一堆的数量除以中值求得吃完这堆香蕉所需的时间下限，然后再检查一堆的数量和中值
// 取余是否为0，如果为0则说明正好吃完，如果不为0则需要额外增加1个小时。计算完成后检查吃完全部
// 香蕉的时间是否大于警卫不在的时间h。如果该时间不大于h，则说明比中值更大的时间都一定能吃完全部
// 香蕉，所以需要将上界调小至中值mid。如果该时间大于h，则说明比中值更小的时间都不能吃完全部
// 香蕉，所以需要将下界调大至mid + 1。最后返回的值为最终求得的上界high
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid;
        int timeSpent;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            timeSpent = 0;

            for(int& pile : piles) {
                timeSpent += (pile / mid) + (pile % mid != 0);
            }

            if(timeSpent <= h) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return high;
    }
};
