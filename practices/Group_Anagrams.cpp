#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 思路：排序+哈希表
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        // 遍历整个数组，将每一项的字符串进行排序，然后插入到对应的哈希表表项中
        for(string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        for(auto& p : mp) {
            res.push_back(p.second);
        }

        return res;
    }
};
