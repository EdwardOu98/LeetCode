#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<int, int> memo;
    int EggDrop(int k, int n) {
        // If the result has been calculated before, return the previous result
        if(memo.count(n * 100 + k)) {
            return memo[n * 100 + k];
        }

        int res;
        // If we have only 1 egg, then we need to drop the egg for at most n times
        // to find the threshold. If we have 1 floor, then we only need to drop 1
        // time. If we have 0 floor, then we don't need to drop the egg
        if(k == 1 || n <= 1) {
            res = n;
        }
        else {
            int l = 1, r = n;
            while(l + 1 < r) {
                int mid = l + (r - l) / 2;
                // If we drop the egg from the mid-th floor, t1
                // represents the case that the egg is broken,
                // t2 represents the case that the egg is not broken
                int t1 = EggDrop(k-1, mid - 1);
                int t2 = EggDrop(k, n - mid);
                if(t1 < t2) {
                    l = mid;
                }
                else if(t1 > t2) {
                    r = mid;
                }
                else {
                    l = r = mid;
                }
            }
            res = 1 + min(max(EggDrop(k-1, l-1), EggDrop(k, n-l)), 
                          max(EggDrop(k-1, r-1), EggDrop(k, n-r)));
        }
        memo[n * 100 + k] = res;
        return res;
    }
public:
    int superEggDrop(int k, int n) {
        return EggDrop(k, n);
    }
};
