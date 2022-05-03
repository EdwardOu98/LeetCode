#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(void) {
    set<int> bound; // Record the boundary of each sections
    map<int, int> m; // Record the number of occurrences of 
                     // segment sums
    // Number of cargo
    int n;
    cin >> n;
    bound.insert(0);
    bound.insert(n+1);

    // Weight of each cargo
    int w;
    int prefixSum[n+1];
    prefixSum[0] = 0;
    for(int i = 0; i < n; ++i) {
        cin >> w;
        prefixSum[i+1] = prefixSum[i] + w;
    }

    // cargo index to be taken out
    int pos;
    for(int i = 0; i < n; ++i) {
        cin >> pos;
        auto idx = bound.lower_bound(pos); // Find the minimum boundary
                                           // that's not smaller than pos
        int right = (*idx) - 1; // The prefixSum to the right of the current
                                // cargo index is at (*idx) - 1
        int left = *(--idx);    // The prefixSum to the left of the current
                                // cargo index is indicated by the previous
                                // iterator of the idx
        
        // Calculate the sum of the current segment
        int seg = prefixSum[right] - prefixSum[left];
        // If this sum has occurred before (or this segment have not been
        // divided), we decrement the count of this segment count. If the
        // segment count is already at 1, that means the last segment with
        // this segment sum is divided into two parts. Then we simply erase
        // it from the map
        if(m.count(seg)) {
            if(m[seg] == 1) {
                m.erase(seg);
            }
            else {
                --m[seg];
            }
        }

        // The sum of elements to the left of the current element
        int leftSum = prefixSum[pos - 1] - prefixSum[left];
        // The sum of elements to the right of the current element
        int rightSum = prefixSum[right] - prefixSum[pos];
        // Add the current index into the boundary set
        bound.insert(pos);
        // Put the left and right segment sum into the map
        ++m[leftSum];
        ++m[rightSum];
        // Ouput the last element in the map
        cout << m.rbegin()->first << endl;
    }

    return 0;
}
