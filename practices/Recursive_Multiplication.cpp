using namespace std;

class Solution {
public:
    int multiply(int A, int B) {
        // If either A or B is 0, return 0
        if(A == 0 || B == 0) {
            return 0;
        }

        // If A is 1, return B
        if(A == 1) {
            return B;
        }

        // If B is 1, return A
        if(B == 1) {
            return A;
        }

        // Use the smaller 1 between A and B as the recurrsion control
        // to minimize the levels of recurrsion we need to do
        return A < B ? B + multiply(A - 1, B) : A + multiply(A, B - 1);
    }
};
