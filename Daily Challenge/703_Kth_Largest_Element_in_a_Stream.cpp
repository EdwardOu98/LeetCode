#include <queue>

using namespace std;

class KthLargest {
private:
    struct comp {
        bool operator() (const int& a, const int& b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, comp> pq;
    int k;
public:
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for(int& num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
