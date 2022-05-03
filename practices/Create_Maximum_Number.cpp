#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> maxNumber(vector<int>& nums, int k) {
        // To generate a number with k digit from an n-length sequence,
        // we need to drop n - k digits. 
        int nums2Drop = nums.size() - k;
        vector<int> out;
        
        for(int num : nums) {
            // If we can still drop more numbers and the output array is not
            // empty and the current digit is greater than the last digit in
            // the output array, we drop the last digit of the output array
            // and decrement the drop count
            while(nums2Drop && !out.empty() && num > out.back()) {
                out.pop_back();
                --nums2Drop;
            }
            out.push_back(num);
        }
        // Trim the output array size to k
        out.resize(k);
        return out;
    }
    
    vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
        vector<int> out;
        
        while(nums1.size() + nums2.size()) {
            vector<int>& curr = nums1 > nums2 ? nums1 : nums2;
            out.push_back(*curr.begin());
            curr.erase(curr.begin());
        }
        
        return out;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> best;
        
        for(int k1 = max(0, k - n2); k1 <= min(k, n1); ++k1) {
            best = max(best, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k - k1)));
        }
        
        return best;
    }
};
