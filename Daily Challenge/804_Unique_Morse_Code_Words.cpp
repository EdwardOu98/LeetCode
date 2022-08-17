#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> uset;
        
        for(string& s : words) {
            string tmp = "";
            
            for(char& c : s) {
                tmp += morse[c - 'a'];
            }
            
            uset.insert(tmp);
        }
        
        return (int) uset.size();
    }
};
