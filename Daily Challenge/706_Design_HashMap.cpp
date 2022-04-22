#include <cstring>

using namespace std;

class MyHashMap {
private:
    static const int MOD = 1e6 + 7;
    int mp[MOD];
    
    int hash(int key) {
        return key % MOD;
    }
public:
    MyHashMap() {
        memset(mp, -1, sizeof(mp));
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        mp[idx] = value;
    }
    
    int get(int key) {
        int idx = hash(key);
        return mp[idx];
    }
    
    void remove(int key) {
        int idx = hash(key);
        mp[idx] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
