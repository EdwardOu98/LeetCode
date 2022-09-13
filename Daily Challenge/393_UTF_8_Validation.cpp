#include <vector>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int todo = 0; // Number of bytes to be processed
        
        int mask1 = 1 << 7;
        int mask2 = 1 << 6;
        
        for(int i = 0; i < data.size(); ++i) {
            if(todo == 0) {
                int mask = 1 << 7;
                
                while((mask & data[i]) != 0) {
                    ++todo;
                    mask >>= 1;
                }
                
                if(todo == 0) {
                    continue;
                }
                
                if(todo > 4 || todo == 1) {
                    return false;
                }
            }
            else {
                if(!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)) {
                    return false;
                }
            }
            --todo;
        }
        
        return todo == 0;
    }
};
