#include <vector>

using namespace std;

class Solution {
// 思路：对输入数组求前缀和，然后通过随机函数生成一个1到整个数组的和之间的数字
// 最后通过二分查找的方法确定该数字的插入位置。该插入位置即为所求下标
private:
    int sum = 0;
    int N;
    vector<int> vec;
public:
    Solution(vector<int>& w) {
        N = w.size();
        for(int& i : w) {
            sum += i;
            vec.push_back(sum);
        }
    }
    
    int pickIndex() {
        int num = rand() % sum + 1;
        int left = 0, right = N - 1, mid;

        while(left < right) {
            mid = left + (right - left) / 2;
            if(vec[mid] == num) {
                return mid;
            }
            else if(vec[mid] < num) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
