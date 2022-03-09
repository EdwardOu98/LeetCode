#include <vector>

using namespace std;

class Solution {
private:
    vector<int> CountingSortMethod(vector<int>& arr, int k) {
        vector<int> res;
        int counter[10001] = {0};
        for(int n : arr) {
            ++counter[n];
        }

        int i = 0;
        while(k > 0 && i <= 10000) {
            if(counter[i]) {
                while(counter[i]-- > 0 && k-- > 0) {
                    res.push_back(i);
                }
            }
            ++i;
        }
        return res;
    }

    vector<int> quickSortMethod(vector<int>& arr, int k) {
        int n = arr.size();
        quickSort(arr, 0, n - 1);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    void quickSort(vector<int>& arr, int low, int high) {
        int temp;
        int i = low, j = high;
        if(low < high) {
            temp = arr[low];
            while(i < j) {
                while(i < j && arr[j] >= temp) {
                    --j;
                }
                if(i < j) {
                    arr[i] = arr[j];
                    ++i;
                }
                while(i < j && arr[i] < temp) {
                    ++i;
                }
                if(i < j) {
                    arr[j] = arr[i];
                    --j;
                }
            }
            arr[i] = temp;
            quickSort(arr, low, i - 1);
            quickSort(arr, i + 1, high);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // return quickSortMethod(arr, k);
        return CountingSortMethod(arr, k);
    }
};
