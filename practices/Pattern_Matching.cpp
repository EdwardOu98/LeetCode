#include <string>

using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int countA = 0, countB = 0;
        // Calculate the count of A and B's in the pattern
        for(char& c : pattern) {
            (c == 'a') ? ++countA : ++countB;
        }
        // Length of the value string
        int len = value.length();

        // If the length of the value string is shorter than
        // the pattern string, return false
        if(len + 1 < pattern.length()) {
            return false;
        }

        // Visit all possible length of strings corresponds to A
        // in the pattern
        for(int i = 0; i <= len; ++i) {
            // countA, length of string A, countB, length of stringB satisfy
            // the formula: countA * length of stringA + countB * length of
            // stringB = length of the value string. Given the length of 
            // stringA = i, the length of stringB is length of the value string
            // - i * countA. 
            int lenb = (countB == 0 ? 0 : (len - i * countA) / countB);
            // If the new length of stringB is less than 0, then any
            // length of stringA after the current one will also result
            // in a negative length of stringB. Thus, we can leave the
            // loop
            if(lenb < 0) {
                break;
            }
            // If there exists B in the pattern string and the number
            // (len - i * countA) is not divisible by countB, skip the
            // current round
            if(countB != 0 && (len - i * countA) % countB != 0) {
                continue;
            }
            string str_a, str_b;
            int s = 0;
            bool flag = true;
            for(char& c : pattern) {
                if(c == 'a') {
                    // If stringA is empty, get a new stringA
                    if(str_a.length() == 0) {
                        str_a = value.substr(s, i);
                    }
                    // If the substring doesn't match with the
                    // current stringA, set flag to false and
                    // leave the loop
                    else if(str_a != value.substr(s, i)) {
                        flag = false;
                        break;
                    }
                    // Move the starting index
                    s += i;
                }
                else {
                    // If stringA is empty, get a new stringA
                    if(str_b.length() == 0) {
                        str_b = value.substr(s, lenb);
                    }
                    // If the substring doesn't match with the
                    // current stringB, or stringB is the same
                    // as stringA, set flag to false and leave
                    // the loop
                    else if(str_b != value.substr(s, lenb) || str_b == str_a) {
                        flag = false;
                        break;
                    }
                    // Move the starting index
                    s += lenb;
                }
            }
            // If flag is true after the above loop and we reach
            // the end of the value string, return true
            if(flag && s == len) {
                return true;
            }
        }

        return false;
    }
};
