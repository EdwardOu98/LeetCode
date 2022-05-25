#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // Sort the envelopes on their width in ascending order, then
        // on their height in decending order
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            // Find the smallest height that's larger than the current envelope's
            // height
            auto it = lower_bound(res.begin(), res.end(), envelopes[i][1]);
            // If no such envelope exist, add the current envelope to the result
            // array
            if(it == res.end()) {
                res.push_back(envelopes[i][1]);
            }
            // Otherwise, replace that envelope with the current one to get the 
            // best result
            else {
                *it = envelopes[i][1];
            }
        }
        
        return res.size();
    }
};
