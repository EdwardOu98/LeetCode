#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    // 原理：假设传入的两个数分别为30和3，因为303<330，所以在排序
    // 的过程中30会在3的前面；类似的，如果传入的两个数分别为25和5，
    // 因为255<525，所以25会排在2的前面。如果传入的两个数分别为
    // 42和2，因为242<422，所以2会排在42的前面
    static bool compare(const string& a, const string& b) {
        return (a + b) < (b + a);
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), compare);
        for(string str : strs) {
            res += str;
        }

        return res;
    }
};
