#include <utility>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
typedef pair<int, int> pii;
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pii> heights; // Record the heights of the left and right
                             // edges and their heights of a building
        for(vector<int>& b : buildings) {
            // For the left edge, we make the height value correspond to it
            // negative so that, when we sort the heights array, the left edges
            // always come before the right edges, and we can ensure the result
            // is correct. To correctly sort the heights array, we need to follow
            // the rules below:
            // - If the two edges have different x coordinates, the one with a smaller
            //   x value should come first; 
            // - If the two edges have same x coordinates: 
            //      * If both of them are left edges, the one with a larger height should
            //        come first; 
            //      * If one of them is left edge and the other is right edge, the left
            //        edge should come first. 
            heights.push_back({b[0], -b[2]});
            heights.push_back({b[1], b[2]});
        }
        
        sort(heights.begin(), heights.end());
        multiset<int> mset; // Keeps track of the maximum height
        mset.insert(0);     // Add a 0 to the multiset can simplify
                            // the program
        
        int prev = 0, curr; // Record the previous and current maximum
        
        vector<vector<int>> res;
        
        for(pii h : heights) {
            // If the current edge is a left edge, we add its height
            // to the multiset
            if(h.second < 0) {
                mset.insert(-h.second);
            }
            // If the current edge is a right edge, we remove its height
            // from the multiset
            else {
                mset.erase(mset.find(h.second));
            }
            
            // Get the current maximum of the heights
            curr = *mset.rbegin();
            // If the maximum of the heights changes after
            // we add/remove the new height, it means the 
            // current point should be included in the result
            if(curr != prev) {
                res.push_back({h.first, curr});
                prev = curr;
            }
        }
        
        return res;
    }
};
