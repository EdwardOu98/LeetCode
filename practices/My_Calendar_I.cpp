#include <set>

using namespace std;

class MyCalendar {
private:
    typedef struct Node {
        int start, end;
        bool operator<(const Node& rhs) const {
            return end <= rhs.start;
        }
    } Node;

    set<Node> st;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        return st.insert(Node{start, end}).second;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
