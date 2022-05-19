#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int count[102];
        memset(count, 0, sizeof(count));
        int n = birth.size();
        for(int i = 0; i < n; ++i) {
            ++count[birth[i] - 1900]; // Increment the population when a person is born
            --count[death[i] - 1900 + 1]; // A person will not be included in the 
                                          // population one year after his death
        }

        int maxPop = 0; // Maximum population
        int sum = 0; // Prefix sum
        int yr = 0; // The year with maximum population
        for(int i = 0; i < 102; ++i) {
            // Calculate the prefix sum
            sum += count[i];
            // If the prefix sum up to the i-th year is greater than the maximum
            // population, update the maxPop and year number
            if(sum > maxPop) {
                maxPop = sum;
                yr = i;
            }
        }

        return yr + 1900;
    }
};
