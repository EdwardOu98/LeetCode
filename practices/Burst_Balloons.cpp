#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n;
    int memo[303][303];
    int dfs(vector<int> &nums, int i, int j){
        // Base case: when i is greater than j, we can't
        // get any coins
		if(i > j) {
            return 0;
        }
        
        // If we have calculated this subproblem before, return the previous
        // result
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        
        // When there's only one element (i == j), the number of coins
        // we can get is the coins in the current balloon multiply
        // by the coins in the left balloon (if there's any) and the
        // coins the right balloon (if there's any)
        if(i == j) {
            int temp = nums[i];
            if(i-1 >= 0) {
                temp *= nums[i-1];
            }
            if(i+1 <= n) {
                temp *= nums[i+1];
            }
            return memo[i][j] = temp;
        }
        
        // If we have not calculated this subproblem before, then we try to 
        // leave the kth balloon (i <= k <= j) as the last one to burst and
        // calculate how many coins we will be able to get.
        int maxCoins = 0;
        for(int k = i; k <= j; ++k) {
            int temp = nums[k];
            // After bursting the [i, k-1]th balloons, nums[k] is to the right of
            // the i-1th balloon
            if(i-1 >= 0) {
                temp *= nums[i-1];
            }
            // After bursting the [k+1, j]th balloons, nums[k] is to the left of
            // the j+1th ballon
            if(j+1 < n) {
                temp *= nums[j+1];
            }
            
            // Calculate the maximum coins we can get by bursting the [i, k-1] and
            // [k+1, j]th balloons
            temp += dfs(nums, i, k - 1) + dfs(nums, k + 1, j);
            maxCoins = max(maxCoins, temp);
        }
        
        return memo[i][j] = maxCoins;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        
        // Add 2 dummy balloons (one at the front and one at the end) to the array
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        n = nums.size();
        
        // We start at 1 and n - 2 because the 0th and n-1th balloons are dummies
        return dfs(nums, 1, n - 2);
    }
};
