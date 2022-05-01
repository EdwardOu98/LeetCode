#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) {
            return false;
        }
        int n = org.size();
        bool occurred[n+1];
        memset(occurred, false, sizeof(occurred));
        // Check whether all numbers from 1 to n occurred in seqs
        for(vector<int>& s : seqs) {
            for(int i : s) {
                if(i < 1 || i > n) {
                    return false;
                }
                occurred[i] = true;
            }
        }

        for(int i = 1; i <= n; ++i) {
            if(!occurred[i]) {
                return false;
            }
        }

        unordered_set<int> graph[n + 1];
        int inDegree[n + 1];
        memset(inDegree, 0, sizeof(inDegree));

        for(vector<int>& s : seqs) {
            int m = s.size();
            for(int i = 0; i < m - 1; ++i) {
                if(!graph[s[i]].count(s[i+1])) {
                    graph[s[i]].insert(s[i+1]);
                    ++inDegree[s[i+1]];
                }
            }
        }

        // Perform topological sorting on the graph. Note that, for this question
        // specificly, there should be one and only one vertex with 0 in-degree
        // at any moment
        queue<int> q;
        for(int i = 1; i <= n; ++i) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        int idx = 0;
        while(!q.empty() && q.size() == 1) {
            int curr = q.front();
            q.pop();
            // Compare the current element with the
            // element in the original array at the
            // same position. 
            if(org[idx] != curr) {
                return false;
            }
            ++idx;
            for(int next : graph[curr]) {
                if(--inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return idx == n;
    }
};
