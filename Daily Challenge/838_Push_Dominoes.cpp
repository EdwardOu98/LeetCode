#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        int netForce[n];
        memset(netForce, 0, sizeof(netForce));
        int force = 0;
        
        // Calculate the forces that goes from left to right
        for(int i = 0; i < n; ++i) {
            if(dominoes[i] == 'R') {
                force = n;
            }
            else if(dominoes[i] == 'L') {
                force = 0;
            }
            else {
                force = max(force - 1, 0);
            }
            netForce[i] += force;
        }
        
        // Calculate the forces that goes from right to left
        for(int i = n - 1; i >= 0; --i) {
            if(dominoes[i] == 'L') {
                force = n;
            }
            else if(dominoes[i] == 'R') {
                force = 0;
            }
            else {
                force = max(force - 1, 0);
            }
            netForce[i] -= force;
        }
        
        for(int i = 0; i < n; ++i) {
            dominoes[i] = netForce[i] > 0 ? 'R' : (netForce[i] < 0 ? 'L' : '.');
        }
        
        return dominoes;
    }
};
