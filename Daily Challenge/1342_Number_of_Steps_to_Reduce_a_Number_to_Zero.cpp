using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        // Continue until the number becomes 0
        while(num) {
            // If the number is odd, subtract 1 from it
            if(num % 2) {
                --num;
            }
            // If the number is even, divide it by 2
            else {
                num /= 2;
            }
            ++steps;
        }
        
        return steps;
    }
};
