#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    // DP array, 
    int memo[1001][51];
    
    // Inputs: prefixSum - the prefix sum array; n - size of the initial input array;
    // currIndex - the current starting index of the split; subarrayCount - number of 
    // remaining subarrays;
    // Time complexity: O(n^2 * m), Space complexity: O(m * n)
    int topDownDP(int prefixSum[], int n, int currIndex, int subarrayCount) {
        // If the current case has already been calculated, return the memoized result
        if(memo[currIndex][subarrayCount] != -1) {
            return memo[currIndex][subarrayCount];
        }
        
        // Base case: subarrayCount is 1, which means there's only 1 subarray left, then
        // all of the remaining numbers must go into the subarray
        if(subarrayCount == 1) {
            return memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
        }
        
        // All other cases: use recurrence to determine the minimum largest subarray sum
        // between currIndex and the end of the array with subarrayCount subarrays remaining
        int minLargestSplitSum = INT_MAX;
        // i's range is from currIndex to n - subarrayCount, because we need to leeave some
        // elements for the remaining subarrays
        for(int i = currIndex; i <= n - subarrayCount; ++i) {
            // Calculate the sum of all elements in the first split
            int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
            // Find the largest subarray sum in the array
            int largestSplitSum = max(firstSplitSum, topDownDP(prefixSum, n, i + 1, subarrayCount - 1));
            // Find the minimum largest sum among all combinations
            minLargestSplitSum = min(minLargestSplitSum, largestSplitSum);
            
            // If the minimum largest subarray sum is smaller than or equal to the sum of the first 
            // split, then we can break from the loop because we have found the right split point;
            if(firstSplitSum >= minLargestSplitSum) {
                break;
            }
        }
        
        return memo[currIndex][subarrayCount] = minLargestSplitSum;
    }
    
    // Inputs: prefixSum - the prefix sum array; n - size of the initial input array;
    // m - number of subarrays
    // Time and space complexity is the same as top-down DP
    int bottomUpDP(int prefixSum[], int n, int m) {
        
        for(int subarrayCount = 1; subarrayCount <= m; ++subarrayCount) {
            for(int currIndex = 0; currIndex < n; ++currIndex) {
                // Base Case: if there's only 1 subarray, then all of the remaining
                // elements must go into the subarray
                if(subarrayCount == 1) {
                    memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
                    continue;
                }
                
                // All other cases: find the minimum largest subarray sum between currIndex
                // and the end of the input array with subarrayCount subarrays remaining
                int minLargestSplitSum = INT_MAX;
                // Check comment of the same section in topDownDP for explanation of the
                // following loop
                for(int i = currIndex; i <= n - subarrayCount; ++i) {
                    int firstSplitSum = prefixSum[i+1] - prefixSum[currIndex];
                    int largestSplitSum = max(firstSplitSum, memo[i+1][subarrayCount-1]);
                    minLargestSplitSum = min(minLargestSplitSum, largestSplitSum);
                    
                    if(firstSplitSum >= minLargestSplitSum) {
                        break;
                    }
                }
                
                memo[currIndex][subarrayCount] = minLargestSplitSum;
            }
        }
        
        return memo[0][m];
    }
    
    // Find the minimum number of subarrays required such that the sum
    // of each subarray is not larger than maxSum
    int minimumSubarraysRequired(vector<int>& nums, int maxSum) {
        int currentSum = 0;
        int subarrayCount = 1; // There must be at least one subarray
        
        for(int& num : nums) {
            // Add an element to the current subarray if the addition won't
            // make the current sum larger than maxSum
            if(num + currentSum <= maxSum) {
                currentSum += num;
            }
            // Otherwise we need to split the array and reset the sum
            else {
                currentSum = num;
                ++subarrayCount;
            }
        }
        
        return subarrayCount;
    }
    
    int binarySearch(vector<int>& nums, int sum, int maxElem, int m) {
        // The left boundary is the largest element in the array, and the right
        // boundary is the sum of the entire array
        int left = maxElem, right = sum, mid;
        int minSum = 0;
        
        while(left <= right) {
            // Find the mid value, which is the maximum sum we are allowed to obtain
            mid = left + (right - left) / 2;
            
            // If we are able to split thee array into less than or equal to m
            // parts while the sum of each part doesn't exceed the mid value,
            // then we have a potential answer and we can bring the right boundary
            // down to try finding a smaller maximum subarray sum
            if(minimumSubarraysRequired(nums, mid) <= m) {
                right = mid - 1;
                minSum = mid;
            }
            else {
                left = mid + 1;
            } 
        }
        
        return minSum;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int maxElem = INT_MIN;
        
        // Calculate Prefix Sum
        int prefixSum[n + 1];
        memset(prefixSum, 0, sizeof(prefixSum));
        for(int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
            maxElem = max(maxElem, nums[i-1]);
        }
        
        // Initialize DP array
        memset(memo, -1, sizeof(memo));
        
        // return topDownDP(prefixSum, n, 0, m);
        // return bottomUpDP(prefixSum, n, m);
        return binarySearch(nums, prefixSum[n], maxElem, m);
    }
};
