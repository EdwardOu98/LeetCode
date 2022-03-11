using namespace std;

class Solution {
// 思路：虽然不能使用if语句，但可以使用if语句的语义，
// 即通过“骤死性评估”这一语言特性进行判断。所谓骤死性评估
// 是指在逻辑运算符and左侧的表达式未假时，右侧的表达式将不
// 再进行评估。
public:
    int sumNums(int n) {
        int res = n;
        n && (res += sumNums(n - 1));
        return res;
    }
};
