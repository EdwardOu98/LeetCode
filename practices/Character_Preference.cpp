#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* Problem:
 * A likes E but doesn't like F. Given an n-length string consisted of
 * only E and F, find the substring that has the maximum difference 
 * between the count of E and that of F. 
 */

// Idea: If we see E as 1 and F as -1, the problem is the same as calculating
// the maximum sum of substrings
int main(void) {
    int n;

    cin >> n;

    string s;

    cin >> s;

    int maxDiff = 0, sum = 0;

    for(char& c: s) {
        // If the current character is E, we add 1 to the sum
        // If the current character is F, we subtract 1 from the sum
        sum += (c == 'E') ? 1 : -1;
        // If the sum becomes less than 0, that means we have more
        // F than E in the current substring, thus, we need to reset 
        // the sum
        if(sum < 0) {
            sum = 0;
        }
        maxDiff = max(maxDiff, sum);
    }

    cout << maxDiff << endl;

    return 0;
}
