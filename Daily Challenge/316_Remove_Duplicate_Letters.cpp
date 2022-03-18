#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counter[26] = {0}; // 记录s中每个字母出现的次数
        int visited[26] = {0}; // 记录对每个字母的访问情况
        string res;
        
        for(char c : s) {
            ++counter[c - 'a'];
        }
        
        // 遍历整个字符串
        for(char c : s) {
            // 减少当前字母的计数
            --counter[c - 'a'];
            
            // 如果当前字母之前已经访问过，则跳过当前轮
            if(visited[c - 'a']) {
                continue;
            }
            // 如果res串不为空，检查当前字母是否小于串的最后一个字母；
            // 如果小于，检查后续串中是否仍有结果串中最后一个字母；
            // 如果有，将结果串的最后一个字母弹出，并将该字母的访问状态
            // 设为0。这么做是为了保证最后返回的结果串最小且包含输入串
            // 中的所有字母
            while(!res.empty() && c < res.back() && counter[res.back() - 'a']) {
                visited[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(c);
            visited[c - 'a'] = 1;
        }
        
        return res;
    }
};
