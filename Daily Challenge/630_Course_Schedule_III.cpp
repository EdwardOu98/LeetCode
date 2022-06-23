#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Sort the courses based on their end days
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        // Use a priority queue to store the duration of the chosen courses
        priority_queue<int> pq;
        
        int time = 0;
        
        for(auto& course : courses) {
            int duration = course[0], end = course[1];
            // If the current course can be finished before or on the end day,
            // add its duration to the priority queue
            if(time + duration <= end) {
                time += duration;
                pq.push(duration);
            }
            // If the course can't be finished by the dead line, and its duration
            // is shorter than the longest duration in the queue, remove the
            // longest duration from the queue and add the current one
            else if(!pq.empty() && pq.top() > duration) {
                time += (duration - pq.top());
                pq.pop();
                pq.push(duration);
            }
        }
        
        // After iterating through the courses, we should have a queue with all the
        // courses we can take without missing the deadline
        return pq.size();
    }
};
