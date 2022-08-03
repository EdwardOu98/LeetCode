#include <set>

using namespace std;

class MyCalendar {
private:
    struct Event {
        int start, end;
        
        bool operator<(const Event& rhs) const {
            return end <= rhs.start;
        }
    };
    
    set<Event> s;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        return s.insert(Event{start, end}).second;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
