#include <map>
#include <algorithm>

using namespace std;

class MyCalendarThree {
private:
    map<int, int> m;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int curr = 0, res = 0;
        ++m[start];
        --m[end];
        for(auto& [_, d] : m) {
            curr += d;
            res = max(res, curr);
        }
        
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
