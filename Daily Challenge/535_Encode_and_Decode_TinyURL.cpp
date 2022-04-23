#include <string>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution {
private:
    unordered_map<string, string> urlDB;    // Record the mapping relationship
                                            // between long URL and TinyURL to
                                            // speed up the search
    // Character sets used to generate TinyURL. There are 62 characters
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    string generateCode() {
        string code = "http://tinyurl.com/";
        
        // Randomly choose 6 characters as the code for TinyURL
        for(int i = 0; i < 6; ++i) {
            code += chars[rand() % 62];
        }
        
        return code;
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // If the input long URL has appeared before, return the 
        // TinyURL generated for this URL 
        if(urlDB.count(longUrl)) {
            return urlDB[longUrl];
        }
        
        string code = generateCode();
        // If the code has been used for another long URL, generate
        // a new code until an unused code is found
        while(urlDB.count(code)) {
            code = generateCode();
        }
        // Save the mapping relationship to the DB
        urlDB[longUrl] = code;
        urlDB[code] = longUrl;
        
        // Return the code
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // Return the long URL corresponds to the short URL in DB
        return urlDB[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
