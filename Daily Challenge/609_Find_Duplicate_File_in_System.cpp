#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> umap; // Contents - File Paths
        vector<vector<string>> res;
        
        for(string& path : paths) {
            stringstream ss(path);
            string root; // Root directory
            string s; // File name and content
            getline(ss, root, ' '); // Get the root directory
            
            while(getline(ss, s, ' ')) {
                int pos1 = s.find('('), pos2 = s.find(')');
                string fpath = root + '/' + s.substr(0, pos1);
                string content = s.substr(pos1 + 1, pos2 - pos1 - 1);
                umap[content].push_back(fpath);
            }
        }
        
        for(auto& [_, files] : umap) {
            if(files.size() > 1) {
                res.push_back(files);
            }
        }
        
        return res;
    }
};
