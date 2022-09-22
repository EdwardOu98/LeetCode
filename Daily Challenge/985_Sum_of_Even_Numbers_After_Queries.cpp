#include <vector>

using namesapce std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        
        for(int& n : nums) {
            if(n % 2 == 0) {
                sum += n;
            }
        }
        
        vector<int> res;
        
        for(auto& q : queries) {
            int val = q[0], i = q[1];
            
            if((nums[i] + val) % 2 == 0) {
                if(nums[i] % 2 == 0) {
                    sum += val;
                }
                else {
                    sum += nums[i] + val;
                }
            }
            else {
                if(nums[i] % 2 == 0) {
                    sum -= nums[i];
                }
            }
            nums[i] += val;
            res.push_back(sum);
        }
        
        return res;
    }
};
