#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        vector<map<long long, int> > cnt(n);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                long long diff = (long long) nums[i] - (long long) nums[j];
                int sum = 0;
                if(cnt[j].find(diff) != cnt[j].end()){
                    sum = cnt[j][diff];
                }
                cnt[i][diff] += sum + 1;
                res += sum;
            }
        }
        
        return (int) res;
    }
};
