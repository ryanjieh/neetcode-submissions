class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MAX;
        int kokotime;
        int test;
        while (low != high) {
            test = low + (high - low) / 2;
            kokotime = 0;
            for (auto& pile: piles) {
                kokotime += (pile + test - 1) / test;
            }
            if (kokotime > h) {
                low = test + 1;
            } else {
                high = test;
            }
        }
        return low;
    }
};
