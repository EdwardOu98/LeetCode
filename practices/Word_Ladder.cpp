#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    int unorderSets(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> beginSet, endSet, *set1, *set2;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        
        int wordLen = beginWord.length(), steps = 1;
        
        while(!beginSet.empty() && !endSet.empty()) {
            // Make sure that set1's size is always smaller than or equal to s2's size
            if(beginSet.size() <= endSet.size()) {
                set1 = &beginSet;
                set2 = &endSet;
            }
            else {
                set2 = &beginSet;
                set1 = &endSet;
            }
            
            unordered_set<string> temp;
            ++steps;
            
            for(auto it = set1->begin(); it != set1->end(); ++it) {
                string currWord = *it;
                // For each word in set1, we change one of its characters
                // per time and search for the change result in set2. If 
                // the result exists in set2, that means we have found the
                // shortest transformation sequence and we can return the
                // steps value.
                for(int i = 0; i < wordLen; ++i) {
                    char c = currWord[i];
                    
                    for(char a = 'a'; a <= 'z'; ++a) {
                        currWord[i] = a;
                        if(set2->count(currWord)) {
                            return steps;
                        }
                        // If the change result doesn't exist in set2, then
                        // we need to check whether it exists in the dictionary.
                        // If it exist, we add it to the temp set and erase the
                        // corresponding entry from dictionary to prevent repetitive
                        // calculations
                        if(dict.count(currWord)) {
                            temp.insert(currWord);
                            dict.erase(currWord);
                        }
                    }
                    
                    currWord[i] = c;
                }
            }
            
            // After all calculations for the current level is done, we swap the content
            // of the temp set with set1
            swap(*set1, temp);
        }
        
        return 0;
    }
    
    int usingQueue(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int steps = 1, wordLen = beginWord.length();
        int i, j, n;
        
        while(!q.empty()) {
            n = q.size();
            for(i = 0; i < n; ++i) {
                string currWord = q.front();
                q.pop();
                if(currWord == endWord) {
                    return steps;
                }
                dict.erase(currWord);
                for(j = 0; j < wordLen; ++j) {
                    char c = currWord[j];
                    for(char a = 'a'; a <= 'z'; ++a) {
                        currWord[j] = a;
                        if(dict.count(currWord)){
                            q.push(currWord);
                            dict.erase(currWord);
                        }
                    }
                    currWord[j] = c;
                }
            }
            ++steps;
        }
        
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return usingQueue(beginWord, endWord, wordList);
    }
};
