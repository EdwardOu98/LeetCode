#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Move the current wheel up by 1 slot
    string moveUp(string lock, int i) {
        // If the curreent wheel is at 9,
        // then moving it up by 1 should 
        // get 0
        if(lock[i] == '9') {
            lock[i] = '0';
        }
        else {
            lock[i] += 1;
        }

        return lock;
    }

    // Move the current wheel down by 1 slot
    string moveDown(string lock, int i) {
        // If the current wheel is at 0,
        // then moving it down by 1 should
        // get 9
        if(lock[i] == '0') {
            lock[i] = '9';
        }
        else {
            lock[i] -= 1;
        }

        return lock;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        // string lock = "0000";
        unordered_set<string> visited; // Record the visited code
        unordered_set<string> dead(deadends.begin(), deadends.end()); // Record the deadends
        queue<string> q; // All possible codes by rotating one of the lock's wheels once
        q.push("0000");
        visited.insert("0000");
        int steps = 0;

        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                string lock = q.front();
                q.pop();
                // If the current number is the target, return the number of steps
                if(lock == target) {
                    return steps;
                }
                // If the current number is one of the deadends, skip the current round
                if(dead.count(lock)) {
                    continue;
                }

                // For each of the position of the lock, try to rotate it up or down by
                // one slot. If it's not visited before, add it to the queue and the 
                // visited set
                for(int j = 0; j < 4; ++j) {
                    string n_string = moveUp(lock, j);
                    if(!visited.count(n_string)) {
                        q.push(n_string);
                        visited.insert(n_string);
                    }

                    n_string = moveDown(lock, j);
                    if(!visited.count(n_string)) {
                        q.push(n_string);
                        visited.insert(n_string);
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};
