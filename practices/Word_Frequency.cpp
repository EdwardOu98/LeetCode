#include <unordered_map>

using namespace std;

class WordsFrequency {
private:
    unordered_map<string, int> dict;
public:
    WordsFrequency(vector<string>& book) {
        for(string& s : book) {
            ++dict[s];
        }
    }
    
    int get(string word) {
        return dict[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
