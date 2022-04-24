#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> res;
        int preq[numCourses];
        memset(preq, 0, sizeof(preq));
        
        for(vector<int>& p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            ++preq[p[0]];
        }
        
        queue<int> q;   // Courses that doesn't require and prerequisites or 
                        // the prerequisites have all been completed
        for(int i = 0; i < numCourses; ++i) {
            if(!preq[i]) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            // Add the current course to the result array
            res.push_back(curr);
            // Decrement the number of courses to be taken
            --numCourses;
            for(int& c : adjList[curr]) {
                if(--preq[c] == 0) {
                    q.push(c);
                }
            }
        }
        
        return numCourses ? vector<int>() : res;
    }
};
