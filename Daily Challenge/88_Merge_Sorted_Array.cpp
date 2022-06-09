#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) {
            return;
        }
        int i;
        if(m == 0) {
            for(i = 0; i < n; ++i) {
                nums1[i] = nums2[i];
            }
            return;
        }
        
        i = m - 1;
        int j = n - 1, pos = m + n - 1;
        
        while(i >= 0 && j >= 0) {
            if(nums2[j] >= nums1[i]) {
                nums1[pos] = nums2[j];
                --j;
                --pos;
            }
            else {
                nums1[pos] = nums1[i];
                --i;
                --pos;
            }
        }
        
        while(j >= 0) {
            nums1[pos] = nums2[j];
            --pos;
            --j;
        }
    }
};
