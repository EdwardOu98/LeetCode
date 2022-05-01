#include <string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        
        for(char& c : s) {
            // If current character is 'A', increment the absence count
            if(c == 'A') {
                if(++a == 2) {
                    return false;
                }
            }
            // If current character is 'L', increment the late count
            if(c == 'L') {
                if(++l == 3) {
                    return false;
                }
            } 
            // If current character is not 'L', reset the late count
            else {
                l = 0;
            }
        }
        
        return true;
    }
};
