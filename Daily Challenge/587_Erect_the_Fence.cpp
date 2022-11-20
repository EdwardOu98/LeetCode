#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    long long cross(const vector<int>& a, const vector<int>& b, const vector<int>& c){
        return (b[0] - a[0]) * (long long) (c[1] - b[1]) - (b[1] - a[1]) * (long long) (c[0] - b[0]);
    }
    
    // Sort the trees by their x-coordinates. If two trees have same x-coordinates, 
    // sort them by their y-coordinates
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
    }
    
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        vector<vector<int>> res;
        
        sort(trees.begin(), trees.end(), cmp);
        // Left to right scan
        for(int i = 0; i < n; i++){
            while(res.size() > 1 && cross(res[res.size() - 2], res.back(), trees[i]) < 0){
                res.pop_back();
            }
            res.push_back(trees[i]);
        }
        
        // If after the left to right scan we have included all the trees in the fence, 
        // return the result array
        if(res.size() == n){
            return res;
        }
        
        // Right to left scan
        for(int i = n - 2; i >= 0; i--){
            while(res.size() > 1 && cross(res[res.size() - 2], res.back(), trees[i]) < 0){
                res.pop_back();
            }
            res.push_back(trees[i]);
        }
        
        // Remove the last tree from the result array because it's redundant
        res.pop_back();
        
        return res;
    }
};
