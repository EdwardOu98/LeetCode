#include <unordered_map>
#include <list>
#include <utility> // std::pair

using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> mp; // 用于记录关键字位置
    list<pair<int, int>> cache; // 一个数对的列表，用数对在列表中的排序代表最近使用情况
                                // 越靠近头部的数对距离上次被使用的时间越短
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        // 如果关键字不在cache中则返回-1
        if(it == mp.end()) {
            return -1;
        }
        // 将当前关键字对应的数对移动到cache的最前面，这个函数是常量级的
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        // 如果关键字已存在，则更新对应的值以及最近使用情况，然后返回
        if(it != mp.end()) {
            // 将当前关键字对应的数对移动到cache的最前面，这个函数是常量级的
            cache.splice(cache.begin(), cache, it->second);
            // 更新关键字对应的值
            it->second->second = value;
            return;
        }
        // 如果关键字不存在，则将其插入到cache中。插入前先检查cache是否已满。
        // 如果cache满了，则先将最久没使用(即cache尾部)的数对移除再进行插入。
        if(cache.size() == capacity) {
            int k = cache.back().first;
            cache.pop_back();
            mp.erase(k);
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
