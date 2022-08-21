#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    struct Node {
        unordered_set<int> made, todo;
        Node(unordered_set<int> m, unordered_set<int> t) {
            made = m;
            todo = t;
        }
    };
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.length(), n = target.length();
        queue<int> q;
        bool done[n];
        memset(done, false, sizeof(done));
        stack<int> s;
        vector<Node> a;
        
        for(int i = 0; i <= n - m; ++i) {
            // For each window [i, i + m), a[i] records 
            // info on what needs to be change before we
            // can reverse stamp at this window
            unordered_set<int> made, todo;
            
            for(int j = 0; j < m; ++j) {
                if(target[i+j] == stamp[j]) {
                    made.insert(i+j);
                } 
                else {
                    todo.insert(i+j);
                }
            }
            
            a.push_back(Node(made, todo));
            
            // If we can reverse stamp at i immediately, 
            // enqueue letters from this window
            if(todo.empty()) {
                s.push(i);
                for(int j = i; j < i + m; ++j) {
                    if(!done[j]) {
                        q.push(j);
                        done[j] = true;
                    }
                }
            }
        }
        
        // For each enqueued letter
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            
            // For each window that is potentially affected,
            // j: start of window
            for(int j = max(0, i - m + 1); j <= min(n - m, i); ++j) {
                // The current window is affected
                if(a[j].todo.count(i)) {
                    a[j].todo.erase(i);
                    
                    if(a[j].todo.empty()) {
                        s.push(j);
                        for(auto m : a[j].made) {
                            if(!done[m]) {
                                q.push(m);
                                done[m] = true;
                            }
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(!done[i]) {
                return {};
            }
        }
        
        vector<int> ret;
        while(!s.empty()) {
            ret.push_back(s.top());
            s.pop();
        }
        
        return ret;
    }
};
