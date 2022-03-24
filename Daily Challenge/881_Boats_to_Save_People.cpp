#include <vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i = 0, j = people.size() - 1, res = 0;
        sort(people.begin(), people.end());
        
        // Every boat carries at most 2 people, so we can pair up
        // the lightest and heaviest person in the group. If the sum
        // of their weight is larger than limit, than we carry only
        // the heaviest person with one boat. Otherwise we carry both
        // of them in one boat. 
        while(i <= j) {
            ++res;
            if(people[i] + people[j] <= limit) {
                ++i;
            }
            --j;
        }
        
        return res;
    }
};
