#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        int i, j;
        int product;
        
        // 两数相乘，结果的位数最多为两数的位数之和
        string res(m + n, '0');
        
        // 从两个数的尾部开始做乘法，用第一个数的最后一位分别和第二个数的每一位相乘并将结果相加
        for(i = m - 1; i >= 0; --i) {
            for(j = n - 1; j >= 0; --j) {
                product = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = (product % 10) + '0';
                res[i + j] += product / 10;
            }
        }
        
        int idx = res.find_first_not_of('0');
        
        return idx == -1 ? "0" : res.substr(idx);
    }
};
