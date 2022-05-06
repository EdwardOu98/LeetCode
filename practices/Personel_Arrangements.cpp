#include <iostream>

using namespace std;

int main(void) {
    int n; // Number of personels
    cin >> n;
    int orders[n][n]; // Each person's intention order, lower index means higher intention
    bool picked[n]; // is each area picked
    
    // Get each person's intention
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> orders[i][j];
        }
        picked[i] = false;
    }

    int j;
    for(int i = 0; i < n; ++i) {
        j = 0;
        // If their first intention have been picked, move on to the
        // next one. Continue until the first unpicked area
        while(j < n && picked[orders[i][j] - 1]) {
            ++j;
        }
        cout << orders[i][j] << " ";
        picked[orders[i][j] - 1] = true;
    }

    return 0;
}
