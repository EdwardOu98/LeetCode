#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet {
private:
    vector<int> nums; // 用于顺序存储输入的数字以方便随机存取
    unordered_map<int, int> mp; // 用于存储输入的数字和对应的下标
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // 如果待插入的值已经存在，则返回false
        if(mp.count(val)) {
            return false;
        }
        nums.push_back(val); // 将数字插入数组的末尾，此操作不涉及元素移动，故时间复杂度为O(1)
        mp[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // 如果待删除的值不存在于数组中，则返回false
        if(!mp.count(val)) {
            return false;
        }
        int last = nums.back(); // 取出数组中的最后一个数
        mp[last] = mp[val]; // 交换最后一个数和待删除数字的下标
        nums[mp[val]] = last; // 用数组的最后一个数字覆盖待删除数字
        nums.pop_back(); // 删除数组的最后一位
        mp.erase(val); // 删除map中待删除数字的对应项

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
