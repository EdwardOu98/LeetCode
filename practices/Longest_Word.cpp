#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<string> uset;

    // Sorting conditions: sort the strings on their length in decending
    // order. If the two strings have the same length, sort them in lexical
    // order
    static bool comp(string& a, string& b) {
        if(a.length() == b.length()) {
            return a <= b;
        }
        return a.length() > b.length();
    }

    // Check whether a word is consisted of other words in the dictionary
    bool check(string& word) {
        if(uset.count(word)) {
            return true;
        }
        int n = word.length();
        for(int i = 0; i <= n; ++i) {
            string left = word.substr(0, i), right = word.substr(i);
            // If left is in the dictionary, check whether the right
            // part is also consisted of other words in the dictionary
            if(uset.count(left) && check(right)) {
                return true;
            }
        }

        return false;
    }
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        for(string& word : words) {
            uset.insert(word);
        }

        for(string& word : words) {
            uset.erase(word);
            if(check(word)) {
                return word;
            }
            uset.insert(word);
        }

        return "";
    }
};
