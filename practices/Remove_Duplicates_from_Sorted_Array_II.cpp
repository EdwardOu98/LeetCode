#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        int counter = 0;
        
        for(auto n : nums){
            if(counter < 2 || n > nums[counter-2]){
                nums[counter++] = n;
            }
        }
        
        return counter;
    }
};
