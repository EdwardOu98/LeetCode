using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset; // Keep track of the numbers that had
                                 // been calculated
        int sum;
        while(n != 1) {
            // If n has not occurred before, add it to the set. 
            // Otherwise return false because we entered a loop
            // of n
            if(!uset.count(n)) {
                uset.insert(n);
            }
            else {
                return false;
            }
            
            sum = 0;
            while(n) {
                // Take the lowest digit of n and add its power of 2
                // to sum
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum; // The sum is the next number to be calculated
        }
        
        return true;
    }
};
