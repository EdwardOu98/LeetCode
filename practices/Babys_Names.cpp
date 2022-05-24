#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<string, string> parent, real;
    unordered_map<string, int> freq;

    // Get the parent of input string
    string find(string x) {
        return parent[x] == "" ? x : find(parent[x]);
    }

    void merge(string x, string y) {
        string px = find(x), py = find(y);
        // If the two input strings belong to the same group, we
        // don't need to do anything
        if(px == py) {
            return;
        }
        // Otherwise, we put them into the same group and sum up
        // their frequency
        parent[py] = px;
        freq[px] += freq[py];
    }
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        for(string& s : names) {
            // Find the left parenthesis that separates the name and its frequency
            int pos = s.find('(');
            // Add its frequency to the hash map
            freq[s.substr(0, pos)] = stoi(s.substr(pos + 1, s.length() - pos - 1));
        }

        for(string& s : synonyms) {
            // Find the comma that separates the two names
            int pos = s.find(',');
            // Put the two names into the same group
            merge(s.substr(1, pos - 1), s.substr(pos + 1, s.length() - pos - 2));
        }

        vector<string> res;
        for(string& str : names) {
            string s = str.substr(0, str.find("("));
            string p = find(s);
            // Find the name with minimal lexical order
            real[p] = min(s, real[p] == "" ? s : real[p]);
        }

        for(auto& [name1, name2] : real) {
            res.push_back(name2 + "(" + to_string(freq[find(name1)]) + ")");
        }

        return res;
    }
};
