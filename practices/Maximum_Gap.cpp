#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n;
    int bruteForce(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int gap = nums[1] - nums[0];
        for(int i = 2; i < n; ++i) {
            gap = max(gap, nums[i] - nums[i-1]);
        }
        
        return gap;
    }
    
    int bucketSort(vector<int>& nums) {
        // Find the minimum and maximum element in the input array
        auto lh = minmax_element(nums.begin(), nums.end());
        int l = *lh.first, h = *lh.second;
        // For an array with n elements, and all of its elements falls
        // in the range of [l, h], the gap between any two elements won't
        // be smaller than (h - l) / (n - 1). And because this gap could be
        // zero, we need to take the maximum between it and 1 to make sure
        // the gap we used to create the buckets are meaningful. 
        int gap = max((h - l) / (n - 1), 1);
        // Then there will be at least (h - l) / gap + 1 buckets. For each
        // number in the input array, it will fall into the (num - l) / gap
        // bucket. 
        int m = (h - l) / gap + 1;
        vector<int> minBucket(m, INT_MAX);
        vector<int> maxBucket(m, INT_MIN);
        int i, j;
        for(int num : nums) {
            i = (num - l) / gap;
            if(num < minBucket[i]) {
                minBucket[i] = num;
            }
            if(num > maxBucket[i]) {
                maxBucket[i] = num;
            }
        }
        
        i = 0;
        gap = maxBucket[0] - minBucket[0];
        while(i < m) {
            j = i + 1;
            // Skip empty buckets
            while(j < m && minBucket[j] == INT_MAX && maxBucket[j] == INT_MIN) {
                ++j;
            }
            // If we reach the end of the bucket array, exit the loop
            if(j == m) {
                break;
            }
            
            gap = max(gap, minBucket[j] - maxBucket[i]);
            
            i = j;
        }
        
        return gap;
    }
public:
    int maximumGap(vector<int>& nums) {
        n = nums.size();
        if(n < 2) {
            return 0;
        }
        
        return bucketSort(nums);
    }
};
