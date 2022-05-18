#include <vector>
#include <algorithm>

using namespace std;

class Operations {
public:
    Operations() {

    }
    
    int minus(int a, int b) {
        return a + (-b);
    }
    
    int multiply(int a, int b) {
        if(a == 0 || b == 0) {
            return 0;
        }
        if(a == 1) {
            return b;
        }
        if(b == 1) {
            return a;
        }
        if(a == -1) {
            return -b;
        }
        if(b == -1) {
            return -a;
        }

        int sign = 0;
        if(a < 0) {
            sign += 1;
            a = -a;
        }
        if(b < 0) {
            sign += 1;
            b = -b;
        }
        if(a > b) {
            swap(a, b);
        }

        vector<int> temp, count;
        long t = b;
        int k = 1;
        while(t <= INT_MAX) {
            temp.push_back(t);
            count.push_back(k);
            t += t;
            k += k;
        }

        int res = 0;
        for(int i = minus(temp.size(), 1); i >= 0; i = minus(i, 1)) {
            while(a >= count[i]) {
                a = minus(a, count[i]);
                res += temp[i];
            }
        }

        if(sign == 1) {
            return -res;
        }
        return res;
    }
    
    int divide(int a, int b) {
        if(a == 0) {
            return 0;
        }
        if(b == INT_MAX || b == INT_MIN) {
            return 0;
        }
        if(b == 1) {
            return a;
        }
        if(b == -1) {
            return -a;
        }

        int sign = 0;
        if(a < 0) {
            sign += 1;
            a = -a;
        }
        if(b < 0) {
            sign += 1;
            b = -b;
        }
        if(a < b) {
            return 0;
        }

        long t = b;
        int k = 1;
        vector<int> temp, count;
        while(a >= t) {
            temp.push_back(t);
            count.push_back(k);
            t += t;
            k += k;
        }

        int res = 0;
        for(int i = minus(temp.size(), 1); i >= 0; i = minus(i, 1)) {
            while(a >= temp[i]) {
                a = minus(a, temp[i]);
                res += count[i];
            }
        }

        if(sign == 1) {
            return -res;
        }
        return res;        
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */
