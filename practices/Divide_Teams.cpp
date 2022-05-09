#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

/*
 * Problem: 
 * Find to teams A and B with x and y people respectively such that the
 * sum of average performance of team A and team B can be maximized
 */

class Comp {
public:
    bool operator() (const pii& a, const pii& b) {
        // When a and b have different performance score, the one with larger
        // performance score should go first. When they have the same performance
        // score, the one with smaller index should go first to get the result
        // with minimum lexical order. 
        return a.first != b.first ? a.first > b.first : a.second < b.second;
    }
};

int main(void) {
    int x, y; // x - number of people in team A
              // y - number of people in team B
    cin >> x >> y;
    int total = x + y;
    int performance[total];

    // Get the performance score of each person
    for(int i = 0; i < total; ++i) {
        cin >> performance[i];
    }

    string res(total, '*'); // The result string consisted of x + y characters

    // The sum of average performance is given by Sx / x + Sy / y, where Sx is
    // the sum of performance score in team A and Sy is the sum of performance
    // socre in team B. The formula can be rewritten as (y * Sx + x * Sy) / xy.
    // When x == y, we have (Sx + Sy) / x. It doesn't matter which person goes
    // to which team. Thus, we can simply put the first half of the group into
    // team A and the second half into team B.
    if(x == y) {
        for(int i = 0; i < total; ++i) {
            res[i] = i < x ? 'A' : 'B';
        }
    }
    // When x > y, team B is smaller in size. To maximize the result, we need
    // to maximize the sum of performance score in team B. Thus, we use a 
    // priority queue to store each person's performance score and their index.
    // The first x person should be the ones with lower performance score
    else if(x > y) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i = 0; i < total; ++i) {
            pq.push({performance[i], i});
        }

        // Put the first x people in the queue into team A
        while(x--) {
            pii p = pq.top();
            pq.pop();
            res[p.second] = 'A';
        }

        // Put the rest of the people into team B
        for(int i = 0; i < total; ++i) {
            if(res[i] == '*') {
                res[i] = 'B';
            }
        }
    }
    // When x < y, team A is smaller in size. To maximize the result, we need
    // to maximize the sum of performance score in team A. Thus, we use a 
    // priority queue to store each person's performace score and their index.
    // The last x person should be the ones with higher performance score
    else {
        priority_queue<pii, vector<pii>, Comp> pq;
        for(int i = 0; i < total; ++i) {
            pq.push({performance[i], i});
        }

        // Put the first y person into team B
        while(y--) {
            pii p = pq.top();
            pq.pop();
            res[p.second] = 'B';
        }

        // Put the rest of the people into team A
        for(int i = 0; i < total; ++i) {
            if(res[i] == '*') {
                res[i] = 'A';
            }
        }
    }

    cout << res << endl;

    return 0;
}
