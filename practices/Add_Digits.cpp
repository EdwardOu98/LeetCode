using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // If num has more than 1 digits
        while(num / 10) {
            int temp = 0;
            // Sum up all the digits of num
            while(num) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        
        return num;
    }
};
