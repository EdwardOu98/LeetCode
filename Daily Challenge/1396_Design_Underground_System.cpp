#include <utility>
#include <unordered_map>
#include <string>

using namespace std;

class UndergroundSystem {
private:
    typedef pair<int, int> pii;
    typedef pair<string, int> psi;
    unordered_map<int, psi> checkInMap; // passenger ID - {startStation, checkInTime}
    unordered_map<string, pii> checkOutMap; // Route - {totalTime, passengerCount}
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        psi& p = checkInMap[id];
        // Concatenate the start station and end station to make a route
        string route = p.first + "_" + stationName;
        // Update the total travel time and number of passengers travelled
        // on this route
        checkOutMap[route].first += t - p.second;
        ++checkOutMap[route].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        return (double) checkOutMap[route].first / checkOutMap[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
