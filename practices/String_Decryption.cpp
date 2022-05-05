#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n; // Length of string
    cin >> n;
    string t; // Encrypted string with length n
    cin >> t;
    int start = 0, end = n - 1; // The left and right boundary of
                                // of the decrypted string
    
    // Find the end of the header part
    while(t[start] != 'M') {
        ++start;
    }
    while(t[start] != 'T') {
        ++start;
    }

    // Find the beginning of the tail part
    while(t[end] != 'T') {
        --end;
    }
    while(t[end] != 'M') {
        --end;
    }

    // Get the decrypted string
    cout << t.substr(start + 1, end - start - 1) << endl;

    return 0;
}
