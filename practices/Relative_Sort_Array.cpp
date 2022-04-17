#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> numCount;
        for(int& num : arr1) {
            ++numCount[num];
        }

        vector<int> res;

        for(int& num : arr2) {
            while(numCount[num]-- > 0) {
                res.push_back(num);
            }
            numCount.erase(num);
        }

        for(auto& it : numCount) {
            while(it.second-- > 0) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};
