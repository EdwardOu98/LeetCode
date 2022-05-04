#include <vector>
#include <algorithm>

using namespace std;

// Index wiring: For index between 0 and the middle index, they will be
// mapped to the odd indices. For the rest of the indices, they will be
// mapped to the even indices. 
#define A(i) nums[(1+2*(i))%(n|1)]

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Find the median of the input array
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        int i = 0, j = 0, k = n - 1;
        while(j <= k) {
            if(A(j) > mid) {
                swap(A(i++), A(j++));
            }
            else if(A(j) < mid) {
                swap(A(j), A(k--));
            }
            else{
                ++j;
            }
        }
    }
};
