using namespace std;

class Solution {
    // Idea: we will first calculate the number of valid attendance sequence
    // with only 'P' and 'L'. After that, we sill considering inserting 'A'
    // into the sequences
public:
    int checkRecord(int n) {
        const long MOD = 1e9 + 7;
        long P[n+1]; // Valid attendence sequence end with P
        long PorL[n+1]; // Valid attendence sequence end with P or L
        PorL[0] = P[0] = 1; // When there are 0 characters, there's only one valid sequence (Empty)
        P[1] = 1;    // When the sequence length is 1, there's one way to have a valid sequence end
                     // with 'P', which is 'P' itself
        PorL[1] = 2; // When the sequence length is 1, there're two ways to have a valid sequence end
                     // with 'P' or 'L', which is 'P' and 'L'
        
        for(int i = 2; i <= n; ++i) {
            P[i] = PorL[i-1]; // To have a valid sequence end with 'P', we simply append 'P' to the
                              // end of a sequence end with 'P' or 'L'
            PorL[i] = (P[i] + P[i-1] + P[i-2]) % MOD; // To have a valid sequence end with 'P' or 'L',
                                                      // we can append a 'P' to the end of the previous
                                                      // sequence (P[i]), append an 'L' (P[i-1]), or 
                                                      // append two 'L's (P[i-2]). To avoid overflow, 
                                                      // mod the result with 1e9 + 7.
        }
        
        long res = PorL[n]; // Base case: When the n-length sequence contains only 'P' and 'L'
        for(int i = 0; i < n; ++i) {
            // When we want to insert an 'A' at index i, the total possible sequences is the number
            // of valid sequences with i characters multiplies with the number of valid sequences with
            // n - i - 1 characters
            long temp = (PorL[i] * PorL[n-i-1]) % MOD;
            res = (res + temp) % MOD;
        }
        
        return res;
    }
};
