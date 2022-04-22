#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int threshold;
    
    int boyerMooreVoting(vector<int>& nums) {
        int count = 0;
        int ret;
        
        // When count is 0, we change the return value
        // to the current number. 
        for(int& num : nums) {
            if(!count) {
                ret = num;
            }
            // When the return value is the same as the
            // current number, count += 1. When the return
            // value is different from the current number,
            // count -= 1. Because the majority element 
            // has more counts than other numbers, it's more
            // likely to stay after we iterate through the
            // entire string
            count += (ret == num) ? 1 : -1;
        }
        
        return ret;
    }
    
    int bruteForce(vector<int>& nums) {
        // Iterate through the entire array
        // and count the times of occurence
        // of each element. Return -1 if 
        // majority element doesn't exist.
        // This method results in TLE.
        
        for(int num : nums) {
            int count = 0;
            
            for(int n : nums) {
                if(n == num) {
                    ++count;
                }
            }
            
            if(count > threshold) {
                return num;
            }
        }
        
        return -1;
    }
    
    int hashMap(vector<int>& nums) {
        // Use a hashmap to store the
        // counts of each number in the
        // array. Then find the one with
        // counts more than the threshold
        unordered_map<int, int> m;
        
        for(int num : nums) {
            ++m[num];
        }
        
        for(auto p : m) {
            if(p.second > threshold) {
                return p.first;
            }
        }
        
        return -1;
    }
    
    int sorting(vector<int>& nums) {
        // Sort the array, and the target
        // number should always fall on the
        // mid point of the array
        sort(nums.begin(), nums.end());
        return nums[threshold];
    }
public:
    int majorityElement(vector<int>& nums) {
        // threshold = nums.size() / 2;
        // return hashMap(nums);
        return boyerMooreVoting(nums);
    }
};
