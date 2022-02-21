#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int threshold;
    
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
        threshold = nums.size() / 2;
        return hashMap(nums);
    }
};

