#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // Get a list of words that can be obtained by changing only one character in the
    // input word
    vector<string> getNeighbors(string word, unordered_set<string>& dict) {
        vector<string> res;
        int n = word.length();
        for(int i = 0; i < n; ++i) {
            char c = word[i];
            for(char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if(dict.count(word)) {
                    res.push_back(word);
                }
            }
            word[i] = c;
        }

        return res;
    }

    vector<bool> visited;
    vector<string> res;
    vector<string> path;
    bool flag; // Whether we have found a path to endWord

    // Check how many characters string a and string b differed by
    // and return true if they differed by only one character
    bool oneDiff(const string& a, const string& b) {
        int count = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) {
                ++count;
            }
        }

        return count == 1;
    } 

    void dfs(const string& beginWord, const string& endWord, vector<string>& wordList) {
        // If beginWord is the same as endWord, then we have found a transformation
        // sequence to the endWord, save the result and set flag to true
        if(beginWord == endWord) {
            res = path;
            flag = true;
            return;
        }

        for(int i = 0; i < wordList.size() && !flag; ++i) {
            // If we havn't used this word before and this word is different than
            // beginWord by 1 character, add it to the path and go down one level
            if(!visited[i] && oneDiff(beginWord, wordList[i])) {
                visited[i] = true;
                path.push_back(wordList[i]);
                dfs(wordList[i], endWord, wordList);
                path.pop_back();
            }
        }
    }
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // dfs search
        visited.resize(wordList.size(), false);
        path.push_back(beginWord);
        dfs(beginWord, endWord, wordList);
        return res;

        // If the endWord doesn't exist in the wordList, return an empty array
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return {};
        }
        // Build the dictionary
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // Word - The sequences end with the word
        unordered_map<string, vector<vector<string>>> umap;
        // Add the beginWord to the map
        umap[beginWord] = {{beginWord}};

        while(!umap.empty()) {
            unordered_map<string, vector<vector<string>>> nmap;
            // For each word in umap
            for(auto& [word, paths] : umap) {
                // If the current word is the endWord, return one of its
                // transformation path
                if(word == endWord) {
                    return umap[word][0];
                }

                // For each path ended with the current word, add one of
                // its neighbor to the path, then add the new path to the
                // neighbor's transformation sequence array. 
                for(string& s : getNeighbors(word, dict)) {
                    for(auto p : paths) {
                        p.push_back(s);
                        nmap[s].push_back(p);
                    }
                }
            }

            // After finishing the transformation in the current level, 
            // remove all the words that has been added to the transformation
            // sequences from the dictionary to prevent repetitive calculations
            for(auto& [word, _] : nmap) {
                dict.erase(word);
            }

            // Swap the content of nmap into umap
            umap.swap(nmap);
        }

        return {};
    }
};
