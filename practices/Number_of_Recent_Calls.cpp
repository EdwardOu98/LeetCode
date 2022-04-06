#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> q;   // 用于记录[t - 3000, t]之间的所有请求
    int currSize;   // 记录当前[t - 3000, t]之间的请求数量
public:
    RecentCounter() {
        currSize = 0;
    }
    
    int ping(int t) {
        // 在队列不空的情况下不断出队t - 3000之前的请求
        while(!q.empty() && (q.front() < (t - 3000))) {
            --currSize;
            q.pop();
        }
        // 将当前请求加入队中
        q.push(t);
        return ++currSize;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
