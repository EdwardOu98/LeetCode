#include <cstring>
#include <iostream>

using namespace std;

/* Problem: 
 * A has a shelf with N rows (indexed 1 - N) and M books (indexed 1 - M). 
 * There are 5 types of operations (opcode - operand1, oprand2):
 * 1 - x, y: A wants to put the x-th book on the y-th row of the shelf. 
 *           If the row of the shelf is locked or the book is in B's hand
 *           or the book is already on the shelf and the row its on is locked,
 *           the operation is invalid
 * 2 - y : Locked the y-th row of the shelf. If the row is already locked,
 *         the operation is invalid
 * 3 - y : Unlock the y-th row of the shelf. If the row is already unlocked,
 *         the operation is invalid
 * 4 - x : B wants to borrow the x-th book. If the book is on the shelf and
 *         the row it's on is not locked, print the row index. Otherwise, 
 *         print -1
 * 5 - x : B wants to return the x-th book. If the book is not in B's hand, 
 *         the operation is invalid
 * There will be a total of Q operations
 */

int main(void) {
    int M, N, Q;
    cin >> M >> N >> Q;
    bool isLocked[N]; // Is the row locked
    bool isWithB[M];  // Is the i-th book in B's hand
    int onRow[M];     // Is the i-th book on shelf and, if yes, on which row

    memset(isLocked, false, sizeof(isLocked));
    memset(isWithB, false, sizeof(isWithB));
    for(int i = 0; i < M; ++i) {
        onRow[i] = -1;
    }

    int opCode, x, y;
    for(int i = 0; i < Q; ++i) {
        // Get the opCode
        cin >> opCode;
        if(opCode == 1) {
            cin >> x >> y;
            // If the opcode is 1, the x-th book is not in B's hand, and the
            // y-th row of the shelf is not locked, put the x-th book on the
            // y-th row of the shelf
            if(isWithB[x-1] || isLocked[y-1] || (onRow[x-1] != -1 && isLocked[onRow[x-1]])) {
                continue;
            }
            onRow[x-1] = y-1;
        }
        else if(opCode == 2) {
            cin >> y;
            // If opCode is 2, lock the y-th row
            isLocked[y-1] = true;
        }
        else if(opCode == 3) {
            cin >> y;
            // If opCodee is 3, unlock the y-th row
            isLocked[y-1] = false;
        }
        else if(opCode == 4) {
            cin >> x;
            // If opCode is 4, the x-th book is on the shelf and the
            // row it's on is not locked, print the row id it's on, 
            // set isWithB[x-1] to true, set onRow[x-1] to -1
            if(onRow[x-1] != -1 && !isLocked[onRow[x-1]]) {
                cout << onRow[x-1] + 1 << endl;
                isWithB[x-1] = true;
                onRow[x-1] = -1;
            }
            else {
                cout << -1 << endl;
            }
        }
        else if(opCode == 5) {
            cin >> x;
            isWithB[x-1] = false;
        }
    }
    return 0;
}
