#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // Array of prime numbers. Each character corresponds to one prime number
    const int a[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
                       67, 71, 73, 79, 83, 89, 97, 101};
    // Prevent overflow
    const int MOD = 1e9 + 7;

    vector<vector<string>> mapAndSort(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for(string& s : strs) {
            string str = s;
            sort(str.begin(), str.end());
            umap[str].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& [_, vs] : umap) {
            res.push_back(vs);
        }

        return res;
    }

    // Get the hash value of a string. The hash value is determined by 
    // the characters in the string. Strings that have the exact same
    // character set will have the same hash value
    int getHash(string& s) {
        long val = 1;
        for(char& c : s) {
            val = (val * a[c - 'a']) % MOD;
        }
        return val;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> umap;

        // Calculate the hash value of each string and add it
        // to the corresponding slot
        for(string& s : strs) {
            int hash = getHash(s);
            umap[hash].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& [_, vs] : umap) {
            res.push_back(vs);
        }

        return res;
    }
};
