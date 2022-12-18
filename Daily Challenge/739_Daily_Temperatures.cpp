#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> stk;
        
        for(int currDay = 0; currDay < n; ++currDay){
            int currTemp = temperatures[currDay];
            
            while(!stk.empty() && temperatures[stk.top()] < currTemp){
                int prevDay = stk.top();
                stk.pop();
                res[prevDay] = currDay - prevDay;
            }
            stk.push(currDay);
        }
        
        return res;
    }
};
