#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
    const int soi = sizeof(int); // Size of int
    int n; // Length of array a and b

    cin >> n;

    int a[n], b[n];

    // Fill array a with inputs
    for(int i = 0; i < n; ++i) {
        cin >> a[i]; 
        b[i] = -1;
    }

    int m; // Number of operations

    cin >> m;

    int OpType;
    int idx; // Output index for array b
    int x, y; // x - index in array a where the elements should start to be copied
              // y - index in array b where the the copied elements should start
              //     to be pasted
    int k;    // Number of elements to be copied

    for(int i = 0; i < m; ++i) {
        cin >> OpType;          // Get the operation type
        if(OpType == 1) {
            cin >> k >> x >> y;
            // If both x + k - 1 and y + k - 1 are not out of bound, then we can
            // safely copy all k elements from a to b;
            // If x + k - 1 is out of bound, then we can only copy n - x + 1
            // elements to the corresponding position in b;
            // If y + k - 1 is out of bound, then wee can onlu copy n - y + 1
            // elements to the corresponding position in b;
            // If both are out of bound, then the number of elements copied
            // is the smaller one between n - x + 1 and n - y + 1.
            k = min({k, n - x + 1, n - y + 1});

            memcpy(b + (y - 1), a + (x - 1), k * soi);
        }
        else {
            cin >> idx;
            cout << b[idx - 1] << endl;
        }
    }

    return 0;
}
