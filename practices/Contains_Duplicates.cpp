#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        
        for(int num : nums) {
            if(uset.count(num)) {
                return true;
            }
            uset.insert(num);
        }
        
        return false;
    }
};
