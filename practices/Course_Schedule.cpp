#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        int pre[numCourses];
        memset(pre, 0, sizeof(pre));
        for(vector<int>& p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            ++pre[p[0]];
        }
        
        queue<int> q;   // Courses that doesn't have any prerequisites or
                        // all the prerequisites have been completed
        
        // If a course doesn't require any prerequisites, add it to the queue
        for(int i = 0; i < numCourses; ++i) {
            if(pre[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            // Decrement number of courses
            --numCourses;
            // Go through the list of courses that needs the current course as a 
            // prerequisite. Decrement the number prerequisites it need. If it
            // becomes 0, add it to the queue
            for(int c : adjList[curr]) {
                if(--pre[c] == 0) {
                    q.push(c);
                }
            }
        }
        
        return numCourses == 0;
    }
};
