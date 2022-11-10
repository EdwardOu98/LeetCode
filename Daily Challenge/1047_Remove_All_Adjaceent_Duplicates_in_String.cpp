#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> dq;
        
        for(char& c : s) {
            if(!dq.empty() && c == dq.back()) {
                dq.pop_back();
            }
            else {
                dq.push_back(c);
            } 
        }
        
        return string(dq.begin(), dq.end());
    }
};
