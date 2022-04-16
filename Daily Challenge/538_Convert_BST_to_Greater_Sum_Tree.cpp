using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int buckets[3] = {0};
        
        for(int& num : nums) {
            ++buckets[num];
        }
        
        int pos = 0;
        
        for(int i = 0; i < 3; ++i) {
            while(buckets[i]--) {
                nums[pos++] = i;
            }
        }
    }
};
