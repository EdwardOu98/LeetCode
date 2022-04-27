#include <string>

using namespace std;

class Solution {
private:
    // Stores number from 1 to 19
    string ones[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                       "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                       "Seventeen", "Eighteen", "Nineteen"};
    // Stores 10's multiple that are greater than or equal to 20 and less than 100
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
                       "Ninety"};
    
    string convert(int num) {
        // If num is greater than or equal to 1 billion
        if(num >= 1e9) {
            return convert(num / 1e9) + " Billion" + convert(num % (int) 1e9);
        }
        // If num is greater than or equal to 1 million
        if(num >= 1e6) {
            return convert(num / 1e6) + " Million" + convert(num % (int) 1e6);
        }
        // If num is greater than or equal to 1 thousand
        if(num >= 1e3) {
            return convert(num / 1e3) + " Thousand" + convert(num % (int) 1e3);
        }
        // If num is greater than or equal to 1 hundred
        if(num >= 100) {
            return convert(num / 100) + " Hundred" + convert(num % 100);
        }
        // If num is greater than or equal to 20
        if(num >= 20) {
            return " " + tens[num / 10] + convert(num % 10);
        }
        // If num is greater than or equal to 1
        if(num >= 1) {
            return " " + ones[num];
        }
        
        // If num is 0, return an empty string
        return "";
    }
public:
    string numberToWords(int num) {
        // If input is 0, return "0". Otherwise, convert the input to
        // words
        return num ? convert(num).substr(1) : "Zero";
    }
};
