#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
private:
    int N;
    int priorityQueue(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void sink(vector<int>& nums, int low, int high) {
        int j = low * 2 + 1;
        int temp = nums[low];
        while(j <= high) {
            // If the current node has a righr child and its right
            // child is greater than left child, then we use the right
            // child to swap with the current node
            if(j < high && nums[j] < nums[j + 1]) {
                ++j;
            }

            if(temp < nums[j]) {
                swap(nums[low], nums[j]);
                low = j;
                j = low * 2 + 1;
            }
            else {
                break;
            }
        }

        nums[low] = temp;
    }

    void buildHeap(vector<int>& nums) {
        for(int i = N / 2; i >= 0; --i) {
            sink(nums, i, N - 1);
        } 
    }

    int heapSort(vector<int>& nums, int k) {
        int count = 0;
        int range = N - 1;

        while(count != k) {
            swap(nums[0], nums[range]);
            --range;
            sink(nums, 0, range);
            ++count;
        }

        return nums[range + 1];
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // return priorityQueue(nums, k);
        N = nums.size();
        buildHeap(nums);

        return heapSort(nums, k);
    }
};
