#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> umap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // If the input value exists in the set, return false
        // because the insertion failed
        if(umap.count(val)) {
            return false;
        }
        
        nums.push_back(val);
        umap[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        // If the input value doesn't exist in the set, return
        // false because we can't delete a value that doesn't exist
        if(!umap.count(val)) {
            return false;
        }
        
        // Get the last element in the array
        int last = nums.back();
        // Copy the last element to the position where
        // the deleted element is located
        umap[last] = umap[val];
        nums[umap[val]] = last;
        // Remove the last element
        nums.pop_back();
        // Remove the input value from the map
        umap.erase(val);
        
        return true;
    }
    
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
