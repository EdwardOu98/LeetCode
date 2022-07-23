#include <vector>
#include <utility>

using namespace std;

class Solution {
private:
    typedef pair<int, int> pii;
    vector<int> res;
    
    void merge(vector<pii>& a, int start, int mid, int end) {
        int i = start, j = mid + 1, n = end - start + 1;
        vector<pii> temp;
        // Reserve space for n elements where n is the size of
        // the subarray from start to end
        temp.reserve(n);
        while(i <= mid && j <= end) {
            // If the front element in the left half is less than
            // or equal to the front element of the right half,
            // add it to the temp array, and update the result
            // array with the number of elements that are smaller
            // than it but come after it. 
            if(a[i].first <= a[j].first) {
                res[a[i].second] += (j - mid - 1);
                temp.push_back(a[i++]);
            }
            else {
                temp.push_back(a[j++]);
            }
        }
        
        // If there are still elements left in the left half and 
        // remained unsorted, add them to the end of the temp array
        // and update the result array
        while(i <= mid) {
            res[a[i].second] += (j - mid - 1);
            temp.push_back(a[i++]);
        }
        
        // If there are still elements left in the right half, add
        // them to the end of the temp array
        while(j <= end) {
            temp.push_back(a[j++]);
        }
        
        // Copy the elements in the temp array to their 
        // corresponding space in the original array
        move(temp.begin(), temp.end(), a.begin() + start);
    }
    
    void mergeSort(vector<pii>& a, int start, int end) {
        // If we have only one or no element return to the
        // previous level
        if(start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return {0};
        }
        
        res.resize(n);
        vector<pii> idx; // Stores array elements and their original index
        
        for(int i = 0; i < n; ++i) {
            idx.push_back({nums[i], i});
        }
        
        mergeSort(idx, 0, n - 1);
        
        return res;
    }
};
