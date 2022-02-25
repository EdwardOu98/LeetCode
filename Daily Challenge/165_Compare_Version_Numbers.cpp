#include <string>
#include <sstream>

using namespace std;

class Solution {
private:
    // Method 1: using istringstream
    int compareUsingIStringStream(string version1, string version2) {
        istringstream v1(version1);
        istringstream v2(version2);
        
        string num1, num2;
        
        while(!v1.eof() || !v2.eof()){
            if(!v1.eof()){
                getline(v1, num1, '.');
            }
            else{
                num1 = "0";
            }
            
            if(!v2.eof()){
                getline(v2, num2, '.');
            }
            else{
                num2 = "0";
            }
            
            if(stoi(num1) == stoi(num2)){
                continue;
            }
            return (stoi(num1) > stoi(num2)) ? 1 : -1;
        }
        
        return 0;
    }

    // Method 2: using indices only
    int compareUsingIndices(string version1, string version2) {
        int i = 0, j = 0, m = version1.length(), n = version2.length();
        int num1 = 0, num2 = 0;
        
        while(i < m || j < n) {
            while(i < m && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                ++i;
            }
            
            while(j < n && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                ++j;
            }
            
            if(num1 > num2) {
                return 1;
            }
            else if(num1 < num2) {
                return -1;
            }
            
            num1 = num2 = 0;
            ++i;
            ++j;
        }
        
        return 0;
    }
public:
    int compareVersion(string version1, string version2) {
        return compareUsingIndices(version1, version2);
        // return compareUsingIStringStream(version1, version2);
    }
};
