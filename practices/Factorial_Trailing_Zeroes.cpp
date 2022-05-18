using namespace std;

class Solution {
private:
    int iterativeApproach(int n) {
        int count = 0;

        while(n >= 5) {
            n /= 5;
            count += n;
        }

        return count;
    }
public:
    // Idea: to generate trailing zeroes, it needs
    // to be a multiple of 10. And because 10 = 2 * 5
    // and there are a lot more multiples of 2, we
    // only need to consider the number of 5's. We should
    // also notice that the multiples of powers of 5 can
    // generate more than one 5. To account for all those
    // 5's we recurrsively devide input by 5 until we have
    // no more 5's. 
    int trailingZeroes(int n) {
        if(n / 5 == 0) {
            return 0;
        }
        
        return n / 5 + trailingZeroes(n / 5);
    }
};
