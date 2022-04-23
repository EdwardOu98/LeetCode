using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // If right is greater than left, the lowest bit will never match. Because
        // the lowest bit changes as the number increases. Thus, we need to shift
        // both number to the right to consider whether the next bit will match. 
        // We continue this comparison until we have left equal to right. To get
        // the original position of this bit, we need to shift the left number
        // to the left as many times as we shift it to the right. 
        return (right > left) ? rangeBitwiseAnd(left >> 1 , right >> 1) << 1 : left;
    }
};
