#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
// Idea: convert the input numbers to strings, sort them
// by the following rule: a + b > b + a (string concatenation). 
// For example, we have two numbers 3 and 30. Because 330
// > 303, 3 should be in front of 30 in the sorted sequence.
// For another example, we have 2 and 25. Because 252 > 225, 
// 25 should be in front of 2 in the sorted sequence
private:
    static bool comp(const string& a, const string& b) {
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        
        for(int& num : nums) {
            strs.push_back(to_string(num));
        }
        
        sort(strs.begin(), strs.end(), comp);
        
        string res = "";
        
        for(string str : strs) {
            // If the input array contains only 0's, 
            // and have already have a 0 in the result
            // string, exit the loop
            if(res == "0" && str == "0") {
                return res;
            }
            res += str;
        }
        
        return res;
    }
};
