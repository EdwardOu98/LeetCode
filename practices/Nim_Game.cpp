using namespace std;

class Solution {
/* Rule of Nim Game (It's actually called Bash game. Nim (Nimes) game is about multiple piles
 * of stones):
 * - Initially, there is a heap of stones on the table.
 * - You and your friend will alternate taking turns, and you go first.
 * - On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
 * - The one who removes the last stone is the winner.
 * The player who goes first can always win if the number of stones is not divisible
 * by 4. 
*/
private:
    // Stack overflow
    bool recurrsion(int n, int memo[]) {
        if(n <= 3) {
            return true;
        }
        // If the current result have been calculated, 
        // check whether the previous result is 1
        if(memo[n] != 0) {
            return memo[n] == 1;
        }
        
        for(int i = 1; i <= 3; ++i) {
            // If we pick i stones, the opponent will
            // pick from the remaining n - i stones.
            // If he cannot win with the remaining stones,
            // then we can say we are able to win when there
            // are n stones when both player plays optimally
            if(!recurrsion(n - i, memo)) {
                memo[n] = 1;
                return true;
            }
        }
        
        // Otherwise, we lose the game
        memo[n] = -1;
        return false;
    }
    
    // Space limit exceeds
    bool linearSpace(int n) {
        // If n <= 0, the input is invalid
        if(n <= 0) {
            return false;
        }
        // If 0 < n <= 3, then the player goes first
        // wins
        if(n < 4) {
            return true;
        }
        
        bool res[n + 1];
        memset(res, false, sizeof(res));
        res[1] = res[2] = res[3] = true;
        for(int i = 4; i <= n; ++i) {
            // res[i-1] represents whether the oponent can win
            // if we pick 1 stone. The same goes for res[i-2]
            //  and res[i-3]
            res[i] = !(res[i-1] && res[i-2] && res[i-3]);
        }
        
        return res[n];
    }
    
    // Time limit exceed
    bool constantSpace(int n) {
        bool res[4] = {false, true, true, true};
        for(int i = 4; i <= n; ++i) {
            res[i % 4] = !(res[(i-1) % 4] + res[(i-2) % 4] + res[(i-3) % 4]);
        }
        
        return res[n % 4];
    }
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};
