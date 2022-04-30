#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_map<string, unordered_map<string, double>> memo; // Dividend - {Divisor, Quotient}
    unordered_set<string> nodes; // Store all nodes that are in the equations array
    vector<double> res;
    
    double evaluate(string a, string b, unordered_set<string>& visited) {
        // If either of the nodes doesn't exist in the nodes set, return 0
        if(!nodes.count(a) || !nodes.count(b)) {
            return 0;
        }
        // If a and b are the same return 1;
        if(a == b) {
            return 1.0;
        }
        // If the result is already given, return the stored value
        if(memo[a].count(b)) {
            return memo[a][b];
        }
        
        // If the result is not calculated before, try to find the right
        // value in the adjacency list of the left number's neighbors. 
        for(auto& [c, q] : memo[a]) {
            if(!visited.count(c)) {
                visited.insert(c);
                double temp = evaluate(c, b, visited);
                if(temp) {
                    return q * temp;
                }
            }
        }
        
        // Return 0 if we cannot find a valid result
        return 0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        
        for(int i = 0; i < n; ++i) {
            // [ai, bi] = ai / bi = values[i]
            memo[equations[i][0]][equations[i][1]] = values[i];
            // If values[i] is not 0, then bi / ai = 1 / values[i]
            if(values[i] != 0) {
                memo[equations[i][1]][equations[i][0]] = 1.0 / values[i];
            }
            nodes.insert(equations[i][0]);
            nodes.insert(equations[i][1]);
        }
        
        vector<double> res;
        for(vector<string> q : queries) {
            unordered_set<string> visited;
            double temp = evaluate(q[0], q[1], visited);
            res.push_back(temp ? temp : -1);
        }
        
        return res;
    }
};
