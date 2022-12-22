#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> roomUnlocked(n, false);
        roomUnlocked[0] = true;
        stack<int> stk;
        stk.push(0);
        
        while(!stk.empty()){
            int i = stk.top();
            stk.pop();
            for(int& key : rooms[i]){
                if(!roomUnlocked[key]){
                    roomUnlocked[key] = true;
                    stk.push(key);
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            if(!roomUnlocked[i]){
                return false;
            }
        }
        
        return true;
    }
};
