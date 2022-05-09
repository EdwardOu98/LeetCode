#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

/* Problem:
 * There are n * m crossroads in the city. There are two properties for the
 * crossroad at the i-th row and j-th column: a[i][j] and b[i][j]. For any
 * non-negative number k:
 * - When time is in the range [k * (a[i][j] + b[i][j]), k * (a[i][j] + b[i][j]) + 
 * a[i][j]), a person can walk to the crossroad at the i±1-th row and j-th column;
 * - When time is in the range [k * (a[i][j] + b[i][j]) + a[i][j], (k + 1) * 
 * (a[i][j] + b[i][j])), a person can walk to the crossroad at the i-th row and
 * j±1-th column. 
 * Each move takes 1 time unit. The person can also choose not to move. 
 * At time 0, the person is at row xs and column ys. Find the minimum time for the
 * person to reach the crossroad at row xt and column yt
 */

 typedef pair<int, int> pii;

int n, m, xs, ys, xt, yt;
// The first two represents up/down movements, and the last two represents left/right
const int dir[2]= {1, -1};
const int MAX_N = 105;
// int a[MAX_N][MAX_N];
// T[i][j] = a[i][j] + b[i][j]. Now the two ranges in the problem description can
// be simplified as:
// [k * T[i][j], k * T[i][j] + a[i][j])
// [k * T[i][j] + a[i][j], (k + 1) * T[i][j])
// int T[MAX_N][MAX_N]; 
// int dist[MAX_N][MAX_N]; // The minimum time it takes to reach the crossroad at [i, j]
// bool visited[MAX_N][MAX_N];

int main(void) {
    cin >> n >> m >> xs >> ys >> xt >> yt;

    int a[n][m];
    int T[n][m];
    memset(a, 0, sizeof(a));
    memset(T, 0, sizeof(T));

    // Get a[i][j]
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    // Calculate T[i][j]
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> T[i][j];
            T[i][j] += a[i][j];
        }
    }

    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    queue<pii> q;
    q.push({xs-1, ys-1});
    visited[xs-1][ys-1] = true;
    int k = 0;
    bool isEnd;

    while(!q.empty()) {
        int qSize = q.size();
        isEnd = false;

        while(qSize--) {
            // Get the front element in the queue
            auto [x, y] = q.front();
            q.pop();
            // If the current index is the destination, exit the loop
            if(x == xt-1 && y == yt-1) {
                isEnd = true;
                break;
            }
            // If the current value is in the range of [k * T[i][j], k * T[i][j] + a[i][j]),
            // we check the up and down movement
            if((0 <= (k % T[x][y])) && ((k % T[x][y]) < a[x][y])) {
                for(int i = 0; i < 2; ++i) {
                    int nx = x + dir[i];
                    // If the new index is out of bound, skip the current round
                    if(nx < 0 || nx >= n) {
                        continue;
                    }
                    // If the new index is not visited yet, add it to the queue and 
                    // set visited to true
                    if(!visited[nx][y]) {
                        q.push({nx, y});
                        visited[nx][y] = true;
                    }
                }
            }
            // If the current value is in the range of [k * T[i][j] + a[i][j], (k + 1) * T[i][j]),
            // we check the left and right movement
            else if((a[x][y] <= (k % T[x][y])) && ((k % T[x][y]) < T[x][y])) {
                for(int i = 0; i < 2; ++i) {
                    int ny = y + dir[i];
                    // If the new index is out of bound, skip the current round
                    if(ny < 0 || ny >= m) {
                        continue;
                    }

                    if(!visited[x][ny]) {
                        q.push({x, ny});
                        visited[x][ny] = true;
                    }
                }
            }
            // In the case where we don't move at all, we add it back to the queue
            q.push({x, y});
        }

        // If we have reached the destination, exit the loop
        if(isEnd) {
            break;
        }
        // Increment the steps variable
        ++k;
    }

    cout << k << endl;
    return 0;
}