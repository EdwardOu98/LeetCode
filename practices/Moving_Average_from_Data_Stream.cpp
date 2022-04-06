#include <queue>

using namespace std;

class MovingAverage {
private:
    int capacity;       // 滑动窗口的大小
    int currSize;    // 当前元素个数
    int sum;         // 窗口内所有元素的和
    queue<int> q;    // 记录窗口内的所有元素
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capacity = size;
        sum = 0;
        currSize = 0;
    }
    
    double next(int val) {
        // 将输入元素加入窗口
        q.push(val);
        sum += val;
        ++currSize;
        // 如果加入后元素个数超过窗口大小限制，则将
        // 最早加入窗口的元素从窗口中移除
        if(currSize > capacity) {
            sum -= q.front();
            q.pop();
            --currSize;
        }

        return (double) sum / currSize;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
