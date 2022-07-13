#include <cstring>
#include <vector>

using namespace std;

class Solution {
private:
    int n; // Lenght of input array
    bool visited[16];
    
    bool dfs(vector<int>& matchsticks, int numsIndex, int currSum, int& subSum, int k) {
        // If we are able to form 3 edges, then we must be able to form the 4th
        // edge with the remaining elements
        if(k == 1) {
            return true;
        }
        
        // If we are able to form an edge with the previous result, we try
        // to form another edge with k - 1
        if(currSum == subSum) {
            return dfs(matchsticks, n - 1, 0, subSum, k - 1);
        }
        
        for(int i = numsIndex; i >= 0; --i) {
            // If the current matchstick has been used, or it's too long for
            // one edge, skip it
            if(visited[i] || ((matchsticks[i] + currSum) > subSum)) {
                continue;
            }
            
            visited[i] = true;
            currSum += matchsticks[i];
            
            if(dfs(matchsticks, i + 1, currSum, subSum, k)) {
                return true;
            }
            
            visited[i] = false;
            currSum -= matchsticks[i];
        }
        
        return false;
    }
    
    // TLE
//     bool dfs(vector<int>& matchsticks, int e[], int i) {
//         if(i == n) {
//             return (e[0] == e[1]) && (e[0] == e[2]) && (e[0] == e[3]);
//         }
        
//         for(int j = 0; j < 4; ++j) {
//             e[j] += matchsticks[i];
//             if(dfs(matchsticks, e, i + 1)) {
//                 return true;
//             }
//             e[j] -= matchsticks[i];
//         }
        
//         return false;
//     }
public:
    bool makesquare(vector<int>& matchsticks) {
        
        
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        if(sum % 4 != 0) {
            return false;
        }
        
        n = matchsticks.size();
        
        memset(visited, false, sizeof(visited));
        
        int subSum = sum / 4;
        
        int currSum = matchsticks[n-1];
        visited[n-1] = true;
        
        return dfs(matchsticks, n - 1, currSum, subSum, 4);
    }
};
