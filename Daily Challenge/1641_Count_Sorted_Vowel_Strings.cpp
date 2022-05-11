using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        // Let the 5 elements in the counter array represents the number
        // of strings started with a, e, i, o, u respectively. When n = 1,
        // we have only 1 string starting with each of the character.
        // When n = 2, we have 5 strings start with a, 4 strings start with
        // e, 3 strings start with i, 2 strings start with o, and 1 string
        // start with u. 
        // When n = 3, we have 15 srings start with a (5 + 4 + 3 + 2 + 1),
        // 10 strings start with e (4 + 3 + 2 + 1), 6 strings start with
        // i (3 + 2 + 1), 3 strings start with o (2 + 1) and 1 string start
        // with u (1).
        // Based on the observation above, we can tell that the number of
        // strings started with the i-th character is the suffix-sum of
        // i-th element (including the i-th element itself). 
        int counter[] = {1, 1, 1, 1, 1};
        for(int i = 1; i <= n; ++i) {
            for(int j = 3; j >= 0; --j) {
                counter[j] += counter[j+1];
            }
        }
        
        return counter[0];
    }
};
