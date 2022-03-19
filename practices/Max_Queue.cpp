#include <queue>
#include <deque>

using namespace std;

class MaxQueue {
private:
    queue<int> q; // 负责记录队列全部元素
    deque<int> dq;// 负责记录队列中的最大元素
public:
    MaxQueue() {

    }
    
    int max_value() {
        // 如果队列为空则返回-1，否则返回dq的队首元素
        return q.empty() ? -1 : dq.front();
    }
    
    void push_back(int value) {
        // 将当前值入队
        q.push(value);

        // 如果当前值大于deque队尾元素，则将队尾元素出队
        while(!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }
        // 将当前元素从队尾加入deque(因为队首为当前队列中的最大值)
        dq.push_back(value);
    }
    
    int pop_front() {
        // 如果队列为空则返回-1
        if(q.empty()) {
            return -1;
        }

        // 取出队首元素
        int ret = q.front();
        q.pop();

        // 检查队首元素是否为队列中的最大元素
        // 如果是则将dq的队首元素出队
        if(ret == dq.front()) {
            dq.pop_front();
        }

        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
