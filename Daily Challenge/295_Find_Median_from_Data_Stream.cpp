#include <queue>

using namespace std;

class MedianFinder {
private:
    // Store the data stream in two halves. The lower
    // half is stored in pq1, the upper half is stored
    // in pq2 and all numbers are negated so that the
    // actual minimum of the second half will be at the
    // top of the priority queue. 
    priority_queue<long> pq1, pq2;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Add the input to pq1
        pq1.push(num);
        // Add the largest element in pq1 to pq2
        pq2.push(-pq1.top());
        // Remove the largest element in pq1
        pq1.pop();
        // If pq2's size is greater than pq1, move the
        // largest (which is actually the smallest element)
        // to pq1
        if(pq1.size() < pq2.size()) {
            pq1.push(-pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        // If pq1's size is greater than pq2's size, it means we
        // currently have odd number of elements in the stream. 
        // Thus, we just need to return the top element of pq1. 
        // Otherwise, we take the average of the top elements 
        // from both queues as the median
        return pq1.size() > pq2.size() ? pq1.top() : (double) (pq1.top() - pq2.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
