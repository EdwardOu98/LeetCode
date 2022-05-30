#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    string encode(int id1, int id2, double similarity) {
        static char buffer[100];
        if(int(similarity * 1e5) % 10 >= 5) {
            sprintf(buffer, "%d,%d: %.4f", id1, id2, similarity + 0.00001);
        }
        else {
            sprintf(buffer, "%d,%d: %.4f", id1, id2, similarity);
        }

        return string(buffer);
    }
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        unordered_map<int, vector<int>> ele2id;
        unordered_map<int, unordered_map<int, int>> id2union;

        const int n = docs.size();
        int s, l; // Smaller group ID, larger group ID
        vector<string> res;

        for(int i = 0; i < n; ++i) {
            for(int& ele : docs[i]) {
                // Record the groups of each element
                ele2id[ele].push_back(i);

                // For each group containing the same element,
                // increment the count of elements shared by
                // both groups
                for(int& id : ele2id[ele]) {
                    // Skip the current group
                    if(id == i) {
                        continue;
                    }

                    s = id < i ? id : i;
                    l = id > i ? id : i;

                    ++id2union[s][l];
                }
            }
        }

        // For groups that have common elements, calculate their similarity
        for(auto& [id1, umap] : id2union) {
            for(auto& [id2, count] : umap) {
                res.push_back(encode(id1, id2, (double) count / (double) (docs[id1].size() + docs[id2].size() - count)));
            }
        }

        return res;
    }
};
