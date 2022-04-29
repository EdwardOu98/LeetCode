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
        // If endWord doesn't exist in the wordList, return 0
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        unordered_set<string> dict(wordList.begin(), wordList.end()); // Dictionary
        queue<string> q; // Stores all words that can be converted from a word by
                         // changing one of its characters
        q.push(beginWord);

        int n, i; // loop variables
        int steps = 1; // Record the length of the transformation sequence

        while(!q.empty()) {
            n = q.size();
            for(i = 0; i < n; ++i) {
                string word = q.front();
                q.pop();
                // If we see the endWord, we can return immediately
                if(word == endWord) {
                    return steps;
                }

                int len = word.length();
                // Change the character of the current word one by one
                for(int j = 0; j < len; ++j) {
                    char c = word[j];
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        word[j] = ch;
                        // If we found the transformed word in the dictionary,
                        // add the word into the queue and remove it from the dictionary
                        // to avoid repetitive calculation
                        if(dict.count(word)) {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = c;
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
