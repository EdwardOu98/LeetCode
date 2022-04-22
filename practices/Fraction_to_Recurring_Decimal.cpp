#include <string>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // If numerator is 0, return "0"
        if(!numerator) {
            return "0";
        }
        
        string res = "";
        if((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }
        
        long long n = llabs(numerator), d = llabs(denominator);
        long long remainder = n % d;
        res += to_string(n / d);
        // If there's no remainder, return the current string
        if(!remainder) {
            return res;
        }
        
        // Add a decimal point at the end of the string
        res += ".";
        
        // Stores the remainder and where they first appear
        // in the string
        unordered_map<long long, int> rs;
        while(remainder) {
            // If the current remainder has occurred earlier,
            // it means we have a recurring decimal. Find the
            // the idex where the remainder first occurred, add
            // a left parenthese there, and then add a right
            // parenthese at the end then return
            if(rs.count(remainder)) {
                res.insert(rs[remainder], "(");
                res += ")";
                return res;
            }
            rs[remainder] = (int) res.size();
            remainder *= 10;
            res += to_string(remainder / d);
            remainder %= d;
        }
        
        return res;
    }
};
