#include <cstring>
#include <iostream>

using namespace std; 

/*
 * Problem:
 * Given an array and the maximum number, find the number of l
 * and r pairs such that:
 * - l <= r
 * - For an element x in the array, if 0 < x < l or r < x < m + 1,
 *   we keep it in the array at the same position.
 * - For the subsequence created, it must be non-decreeasing. 
 */

int m, n; // m - maximum element in the array
          // n - length of the array

bool isValid(int nums[], int l, int r) {
    int prev = -1;
    for(int i = 0; i < n; ++i) {
        // If the current number is less than l or greater than r,
        // keep it in the array
        if((0 < nums[i] && nums[i] < l) || (nums[i] > r && nums[i] < m + 1)) {
            // If the current number is less than the previous
            // number, then the subsequence is invalid. Return
            // false;
            if(nums[i] < prev) {
                return false;
            }
            // If keeping the current number won't make the subsequence
            // invalid, update the prev
            prev = nums[i];
        }
    }
    return true;
}

int main(void) {
    
    cin >> m >> n;
    int nums[n];

    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int res = 0;
    // Iterate l from 1 to m
    for(int i = 1; i <= m; ++i) {
        int l = i;
        int r = m + 1;
        // Use binary search to find the smallest
        // r that satisfy the condition given l
        while(l < r) {
            int mid = l + (r - l) / 2;
            // If we are able to construct a non-decreasing
            // array with r = mid, then any r greater than mid
            // can result in a non-decreasing sequence. Thus, 
            // we should try to find a smaller r that still 
            // satisfy the condition
            if(isValid(nums, i, mid)) {
                r = mid;
            }
            // If the current mid doesn't satisfy the condition
            // then we should try a larger mid
            else {
                l = mid + 1;
            }
        }
        // The result is the number of r's in the range [r, m]
        res += m - r + 1;
        // If the final r is equal to m + 1, that means we can't find
        // any other pairs that can satisfy the condion, thus, we should
        // terminate the loop
        if(r == m + 1) {
            break;
        }
    }

    cout << res << endl;

    return 0;
}
