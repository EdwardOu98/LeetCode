#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class NumArray {
private:
    vector<int> blocks;   // Stores the sum of each block
    vector<int> numArray; // Stores the original array
    int len;              // Number of blocks/length of each block
public:
    NumArray(vector<int>& nums) {
        numArray = nums;
        int n = nums.size();
        // Divide the array into blocks. Number of blocks
        // is determined by the length of the original
        // array. 
        double l = sqrt((double) n);
        len = (int) ceil(n / l);
        blocks.resize(len, 0);
        // Calculate the sum of each block
        for(int i = 0; i < n; ++i) {
            blocks[i / len] += numArray[i];
        }
    }
    
    void update(int index, int val) {
        // Calculate the ID of the block that needs to be updated
        int blockID = index / len;
        // Update the block's sum and the numArray
        blocks[blockID] = blocks[blockID] - numArray[index] + val;
        numArray[index] = val;
    }
    
    int sumRange(int left, int right) {
        // Find the left most and right most block
        int leftID = left / len;
        int rightID = right / len;
        
        int sum = 0;
        
        // If left and right are in the same block
        if(leftID == rightID) {
            for(int i = left; i <= right; ++i) {
                sum += numArray[i];
            }
        }
        else {
            // Add the elements from the left-most block to the sum
            for(int i = left; i <= (leftID + 1) * len - 1; ++i) {
                sum += numArray[i];
            }
            
            // For the blocks in between, we simply add their partial
            // sum to the result
            for(int i = leftID + 1; i < rightID; ++i) {
                sum += blocks[i];
            }
            
            // Add the elements from the right-most block to the sum
            for(int i = rightID * len; i <= right; ++i) {
                sum += numArray[i];
            }
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
