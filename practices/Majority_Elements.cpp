#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int threshold;
    
    int boyerMooreVoting(vector<int>& nums) {
        int count = 0, res;
        // Find a candidate for the majority element
        for(int& n : nums) {
            if(count == 0) {
                res = n;
            }
            if(n == res) {
                ++count;
            }
            else {
                --count;
            }
        }

        // Calculate the count for the candidate
        count = 0;
        for(int& n : nums) {
            if(n == res) {
                ++count;
            }
        }

        int len = nums.size();

        // If the count of candidate is greater than half of
        // the length of the input array, the candidate is the
        // majority element. Otherwise, the input array doesn't
        // have a majority element, return -1. 
        return count > len / 2 ? res : -1;
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
