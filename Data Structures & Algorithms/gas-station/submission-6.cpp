class Solution {
public:
    int bestStation = -1;
    int cumDist = 0;
    int cumFuel = 0;
    int extraFuel = 0;
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //prefix sums
        int numStations = gas.size();
        for (int i = 0; i < numStations; i++) {
            int stationTested = i;
            cumDist += cost[i];
            cumFuel += gas[i];
            int tempExtraFuel = cumFuel - cumDist;
            if (tempExtraFuel <= extraFuel) {
                extraFuel = tempExtraFuel;
                bestStation = i;
            }
        }
        if (cumDist <= cumFuel) {
            return (bestStation + 1) % numStations;
        } else {
            return -1;
        }
    }
};
