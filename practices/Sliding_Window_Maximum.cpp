#include <deque>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> bruteForce(vector<int>& nums, int& k) {
        int n = nums.size();
        vector<int> res;

        for(int i = 0; i < n - k + 1; ++i) {
            int temp = nums[i];
            for(int j = i + 1; j <= i + k - 1; ++j) {
                temp = max(temp, nums[j]);
            }
            res.push_back(temp);
        }

        return res;
    }

    vector<int> monotonicQueue(vector<int>& nums, int& k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq; // 维持一个单调递减队列
        
        for(int i = 0; i < n; ++i) {
            // 如果队列不为空且当前下标对应元素大于队首下标对应元素，则将队首下标出队
            while(!dq.empty() && nums[i] > nums[dq.front()]) {
                dq.pop_front();
            }
            // 将当前下标入队
            dq.push_front(i);

            // 如果队尾元素和当前元素间的距离超过了滑动窗口的大小，则将队尾的下标出队
            if(i - dq.back() >= k) {
                dq.pop_back();
            }
            // 用i >= k - 1来确保我们至少已经扫描完第一个窗口内的所有元素
            // 如果此时队列中不止一个元素，则位于队尾的下标对应的数列元素为当前窗口的最大
            // 值；如果队列中只有一个元素，同样可以通过dq.back()来访问当前窗口的最大元素
            if(i >= k - 1) {
                res.push_back(nums[dq.back()]);
            }
        }

        return res;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) {
            return {};
        }

        if(k <= 1) {
            return nums;
        }

        // return bruteForce(nums, k);
        return monotonicQueue(nums, k);
    }
};
