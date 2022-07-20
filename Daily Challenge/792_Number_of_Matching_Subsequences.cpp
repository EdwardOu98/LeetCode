#include <string>
#include <vector>


using namespace std;

class Solution {
private:
    struct Node {
        const string& word; // A word from the words array
        int idx; // The index of character we are on
        Node(const string& word, int idx) : word(word), idx(idx) {}
    };
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Node> buckets[26];
        int count = 0;
        
        // Put each word into the bucket corresponding to their
        // first character
        for(const string& word : words) {
            char startCh = word[0];
            buckets[startCh - 'a'].push_back(Node(word, 0));
        }
        
        // For each character of s, take out the corresponding
        // bucket, move each node's index 1 step forward. If the
        // new index is the same as the length of the word, 
        // increment the matching subsequence count. Otherwise, 
        // add the word to the bucket corresponding to the character
        // at the index.
        for(char& c : s) {
            auto currBucket = buckets[c - 'a'];
            buckets[c - 'a'].clear();
            for(Node& n : currBucket) {
                ++n.idx;
                if(n.idx == n.word.length()) {
                    ++count;
                }
                else {
                    buckets[n.word[n.idx] - 'a'].push_back(n);
                }
            }
        }
        
        return count;
    }
};
