#include <string>
#include <vector>
#incldue <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // Check whether string t is a prefix of string s
    bool isPrefix(string& s, string& t) {
        return s.find(t) == 0;
    }

public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;
        int n = words.size();

        // Initialize the graph and the indegree array
        for(string& word : words) {
            for(char& c : word) {
                graph[c] = {};
                inDegree[c] = 0;
            }
        }

        for(int i = 0; i < n - 1; ++i) {
            string s = words[i];
            string t = words[i+1];
            // If t is a prefix of s and t's length is smaller than
            // s' length, it violates the rule of a dictionary. Thus,
            // there's no valid character sequence
            if(isPrefix(s, t) && t.length() < s.length()) {
                return "";
            }

            // Find the first different character in s and t
            for(int j = 0; j < s.length() && j < t.length(); ++j) {
                char ch1 = s[j];
                char ch2 = t[j];
                // Put ch2 in ch1's adjacency list and increment ch2's
                // indegree
                if(ch1 != ch2) {
                    if(!graph[ch1].count(ch2)) {
                        graph[ch1].insert(ch2);
                        ++inDegree[ch2];
                    }
                    // Since we only need the lexicographical order of 
                    // the first different character, we can disregard
                    // the remaining characters and proceed with the next
                    // pair of words
                    break;
                }
            }
        }

        // Perform topological sorting on the graph, the result
        queue<char> q;
        for(auto& [ch, count] : inDegree) {
            if(count == 0) {
                q.push(ch);
            }
        }

        string res;
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            for(char ch : graph[c]) {
                if(--inDegree[ch] == 0) {
                    q.push(ch);
                }
            }
        }

        // If the result string's length is not equal to the number of
        // vertices in the graph, that means we have a cycle in the graph
        // and, thus. doesn't have a valid character sequence
        return res.length() != inDegree.size() ? "" : res;
    }
};
