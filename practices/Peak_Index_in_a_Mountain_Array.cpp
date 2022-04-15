#include <vector>

using namespace std;

class Solution {
private:
    int binarySearch(vector<int>& arr) {
        int low = 0, high = arr.size() - 1, mid;

        while(low < high) {
            mid = low + (high - low) / 2;
            if(arr[mid] < arr[mid+1]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }

    int linearSearch(vector<int>& arr) {
        int i = 0;

        while(arr[i] < arr[i+1]) {
            ++i;
        }

        return i;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // return linearSearch(arr);
        return binarySearch(arr);
    }
};
