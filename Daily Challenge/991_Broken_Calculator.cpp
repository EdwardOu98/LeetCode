using namespace std;

class Solution {
public:
    // Instead of doing multiplication and subtraction on
    // startValue, we can do division and addition on target
    // because the effect of early subtractions will be amplified
    // by multiplication, while the effect of early addition will
    // be diminished by division. Thus, it's better to try to reach
    // startValue from target by using division (when target is even)
    // and addition. 
    int brokenCalc(int startValue, int target) {
        int steps = 0; // Keep tract of number of steps
        
        // Conitnue doing this loop until target is smaller than
        // startValue
        while(target > startValue) {
            ++steps;
            // If target is odd, we perform an addition by 1;
            // If target is even, we perform a divition by 2.
            target = (target % 2) ? target + 1 : target / 2;
        }
        
        // After target becomes smaller than startValue, we
        // need to perform startValue - target times of addition
        // to reach startValue
        return steps + startValue - target;
    }
};
