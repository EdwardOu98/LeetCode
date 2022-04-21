#include <vector>
#include <algorithm>

using namespace std;

class MyHashSet {
private:
    const int MOD = 1e4 + 9;
    vector<vector<int>> hashTable;
    
    int hash(int key) {
        return key % MOD;
    }
    
    vector<int>::iterator search(int key) {
        int idx = hash(key);
        return find(hashTable[idx].begin(), hashTable[idx].end(), key);
    }
public:
    MyHashSet() {
        hashTable.resize(MOD);
    }
    
    void add(int key) {
        if(!contains(key)) {
            int idx = hash(key);
            hashTable[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto it = search(key);
        if(it != hashTable[idx].end()) {
            hashTable[idx].erase(it);
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        return search(key) != hashTable[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
