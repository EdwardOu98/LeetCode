#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m=edges.size();
        bool v[n];
        memset(v,false,sizeof(v));
        vector<int> total[n];
        for(int i=0;i<m;i++)
        {
            total[edges[i][0]].push_back(edges[i][1]);
            total[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int p=q.front();
            q.pop();
            if(p == destination) return true;
            for(int i=0;i<total[p].size();i++)
            {
                if(!v[total[p][i]])
                {
                    q.push(total[p][i]);
                    v[total[p][i]]=true;
                }
            }
        }
        return false;
    }
};
