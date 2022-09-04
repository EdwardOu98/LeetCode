#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        
        vector<int> q = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
        
        for(int level = 1; level < n; ++level) {
            vector<int> nextQ;
            
            for(int num : q) {
                int tail = num % 10;
                
                vector<int> nextDigits;
                nextDigits.push_back(tail + k);
                if(k != 0) {
                    nextDigits.push_back(tail - k);
                }
                
                for(int d : nextDigits) {
                    if(0 <= d && d <= 9) {
                        int newNum = num * 10 + d;
                        nextQ.push_back(newNum);
                    }
                }
            }
            
            q.swap(nextQ);
        }
        
        return q;
    }
};
