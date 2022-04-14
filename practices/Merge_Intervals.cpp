#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals.size() == 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int> > result;
        result.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            if(result.back()[1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        
        return result;
    }
};
