#include <vector>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> umap;

        for(int& t : tasks) {
            ++umap[t];
        }

        int res = 0;

        for(auto& [_, freq] : umap) {
            // If there's only one task of the current difficulties, 
            // it's not possible to complete all tasks
            if(freq == 1) {
                return -1;
            }
            res += (freq % 3 == 0) ? freq / 3 : freq / 3 + 1;
        }

        return res;
    }
};
