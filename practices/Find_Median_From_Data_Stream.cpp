#include <queue>	// priority_queue
#include <vector>	// vector<int>
#include <functional>	// greater<int>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Stores the lower half of the stream
    priority_queue<int, vector<int>, greater<int>> minHeap; // Stores the upper half of the stream
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        return (maxHeap.size() > minHeap.size()) ? maxHeap.top() : (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
