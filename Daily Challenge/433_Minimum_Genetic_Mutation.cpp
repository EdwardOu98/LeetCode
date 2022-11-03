#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> dict(bank.begin(), bank.end());
        string ops = "ACGT";
        q.push(start);
        
        int steps = 0;
        
        while(!q.empty()) {
            int qSize = q.size();
            while(qSize-- > 0) {
                string curr = q.front();
                q.pop();
                
                if(curr == end) {
                    return steps;
                }
                
                for(int i = 0; i < curr.length(); ++i) {
                    char ch = curr[i];
                    for(char& c : ops) {
                        curr[i] = c;
                        
                        if(dict.count(curr)) {
                            dict.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = ch;
                }
            }
            
            ++steps;
        }
        
        return -1;
    }
};
