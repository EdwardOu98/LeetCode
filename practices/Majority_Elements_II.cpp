#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        int n = nums.size();
        // Iterate through the array, find two possible
        // numbers
        for(int num : nums) {
            if(num == num1) {
                ++count1;
            }
            else if(num == num2) {
                ++count2;
            }
            else if(!count1) {
                num1 = num;
                count1 = 1;
            }
            else if(!count2) {
                num2 = num;
                count2 = 1;
            }
            else {
                --count1;
                --count2;
            }
        }
        
        count1 = 0;
        count2 = 0;
        // Iterate through the array again, count the number
        // of occurences of the two numbers we found previously
        for(int num : nums) {
            if(num == num1) {
                ++count1;
            }
            else if(num == num2) {
                ++count2;
            }
        }
        
        vector<int> res;
        if(count1 > n / 3) {
            res.push_back(num1);
        }
        if(count2 > n / 3) {
            res.push_back(num2);
        }
        return res;
    }
};
