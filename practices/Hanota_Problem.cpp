#include <vector>

using namespace std;

class Solution {
private:
    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
        // When we have no plates to move, return to the previous level
        if(n == 0) {
            return;
        }
        // Move the plates on A to B through C
        move(n-1, A, C, B);
        // Move the last plate on A to C
        C.push_back(A.back());
        A.pop_back();
        // Move the plates on B to C thorugh A
        move(n - 1, B, A, C);
    }
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A.size(), A, B, C);
    }
};
