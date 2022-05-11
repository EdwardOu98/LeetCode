#include <vector>
#include <deque>

using namespace std;

class AnimalShelf {
private:
    deque<vector<int>> dq;
public:
    AnimalShelf() {
        
    }
    
    void enqueue(vector<int> animal) {
        dq.push_back(animal);
    }
    
    vector<int> dequeueAny() {
        if(dq.empty()) {
            return {-1, -1};
        }
        vector<int> animal = dq.front();
        dq.pop_front();
        return animal;
    }
    
    vector<int> dequeueDog() {
        if(dq.empty()) {
            return {-1, -1};
        }
        int i;
        // Find the oldest dog
        for(i = 0; i < dq.size(); ++i) {
            if(dq[i][1] == 1) {
                vector<int> dog = dq[i];
                dq.erase(dq.begin() + i);
                return dog;
            }
        }

        return {-1, -1};
    }
    
    vector<int> dequeueCat() {
        if(dq.empty()) {
            return {-1, -1};
        }
        int i;
        // Find the oldest cat
        for(i = 0; i < dq.size(); ++i) {
            if(dq[i][1] == 0) {
                vector<int> cat = dq[i];
                dq.erase(dq.begin() + i);
                return cat;
            }
        }

        return {-1, -1};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
