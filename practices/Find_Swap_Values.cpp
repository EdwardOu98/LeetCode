#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
// Idea: Calculate the sum of the two arrays, then calculate their difference.
// The difference must be an even number. The two numbers to be swapped should
// be differed by half of the sum difference
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        unordered_set<int> s1, s2;
        int sum = 0;
        for(int& n : array1) {
            s1.insert(n);
            sum += n;
        }

        for(int& n : array2) {
            s2.insert(n);
            sum -= n;
        }

        // If the difference is not even, return an empty array
        if(sum % 2 != 0) {
            return {};
        }

        sum /= 2;

        for(int n : s1) {
            if(s2.count(n - sum)) {
                return {n, n - sum};
            }
        }

        return {};
    }
};
