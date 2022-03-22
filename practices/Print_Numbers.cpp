#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    string str;
    vector<int> res;

    // 在不考虑潜在的溢出问题的情况下，直接暴力破解即可
    void BruteForce(int& n) {
        int m = pow(10, n);
        for(int i = 1; i <= m - 1; ++i) {
            res.push_back(i);
        }
    }

    void putNumber() {
        int val = stoi(str);
        if(val) {
            res.push_back(val);
        }
    }

    // 考虑到潜在的溢出问题，需要先将数字以字符串的形式暂存
    void dfs(int& n, int idx) {
        if(idx == n) {
            putNumber();
            return;
        }
        for(int i = 0; i < 10; ++i) {
            str[idx] = '0' + i;
            dfs(n, idx + 1);
        }
    }
public:
    vector<int> printNumbers(int n) {
        // BruteForce(n);

        dfs(n, 0);
        return res;
    }
};
