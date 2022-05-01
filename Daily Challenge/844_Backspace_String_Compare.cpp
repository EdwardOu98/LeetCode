#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    bool compareWithStack(string& s, string& t) {
        stack<char> s1, s2;
        for(char& c : s) {
            if(c == '#' && !s1.empty()) 
            {
                s1.pop();
            }
            else  if (c != '#'){
                s1.push(c);
            }
        }
        
        for(char& c : t) {
            if(c == '#' && !s2.empty()) 
            {
                s2.pop();
            }
            else if (c != '#'){
                s2.push(c);
            }
        }
        
        // If s1 and s2 doesn't contain the same number of chatacters, 
        // return false
        if(s1.size() != s2.size()) {
            return false;
        }
        
        while(!s1.empty() && !s2.empty()) {
            if(s1.top() != s2.top()) {
                return false;
            }
            s1.pop();
            s2.pop();
        }
        
        return true;
    }
    
    bool constantSpaceSolution(string& s, string& t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        
        // Build the actual strings starting from the back
        // of the input strings
        while(i >= 0 || j >= 0) {
            // Find the next character in the string s
            while(i >= 0) {
                // If the current character is a backspace character,
                // we record it and skip the next non-backspace character
                if(s[i] == '#') {
                    ++skipS;
                    --i;
                }
                // If the current character is not a backspace character
                // and there are uncleared backspaces, we skip the current
                // character and decrement the skip count
                else if(skipS > 0) {
                    --skipS;
                    --i;
                }
                // Otherwise, we found the next character to build the string
                // from the back
                else {
                    break;
                }
            }
            
            // Find the next character in the string t
            while(j >= 0) {
                // If the current character is a backspace character,
                // we record it and skip the next non-backspace character
                if(t[j] == '#') {
                    ++skipT;
                    --j;
                }
                // If the current character is not a backspace character
                // and there are uncleared backspaces, we skip the current
                // character and decrement the skip count
                else if(skipT > 0) {
                    --skipT;
                    --j;
                }
                // Otherwise, we found the next character to build the string
                // from the back
                else {
                    break;
                }
            }
            
            // If the current characters doesn't match
            if(i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            
            // If one of the strings is empty
            if((i >= 0) != (j >= 0)) {
                return false;
            }
            --i;
            --j;
        }
        
        return true;
    }
public:
    bool backspaceCompare(string s, string t) {
        // return compareWithStack(s, t);
        return constantSpaceSolution(s, t);
    }
};
