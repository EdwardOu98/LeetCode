#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    string findSum(string& a, string& b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        
        while(i >= 0 || j >= 0) {
            // Get the current digit of a and b and calculate their sum
            int sum = (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0) + carry;
            // Update carry and the result string
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
        }
        
        // If the carry is non-zero, add it to the result string
        if(carry) {
            res.push_back(carry + '0');
        }
        
        // Reverse the result string because it's currently inverted, with the most significant
        // digit at the end of the string
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    bool check(string a, string b, string c) {
        // If any of the number contains a leading 0 or the sum's length is smaller than the maximum of a and
        // b's length, we don't need to check anything and return false
        if((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0') || (c.size() > 1 && c[0] == '0') ||
           (c.size() < max((int) a.size(), (int) b.size()))) {
            return false;
        }
        
        // Calculate the sum of a and b
        string sum = findSum(a, b);
        
        // If the sum is equal to c, return true
        if(sum == c) {
            return true;
        }
        // If the length of sum is greater than or equal to c's length or sum doesn't match with c's
        // first i digits, where i is the length of sum, return false
        if((c.size() <= sum.size()) || sum.compare(c.substr(0, sum.size())) != 0) {
            return false;
        }
        // If the sum matches with the first i digits of c, we continue to check whether b + sum is
        // equal to the remaining digit of c
        return check(b, sum, c.substr(sum.size()));
    }
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        // The length of the first number shouldn't exceed half of the original string. 
        // Similarly, the length of the second number shouldn't exceed half of the length
        // of the remaining part
        for(int i = 1; i <= n / 2; ++i) {
            for(int j = 1; j <= (n - i) / 2; ++j) {
                if(check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
