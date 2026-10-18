class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //size is biggest coin x amount
        int numOfWays[5001][101];
        //ascending sort coins
        sort(coins.begin(), coins.end());
        //initialise when only losing cheapest coin
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                numOfWays[i][0] = 1;
            } else {
                numOfWays[i][0] = 0;
            }
        }
        // recursive solving
        for (int j = 1; j < coins.size(); j++) {
            for (int i = 0; i <= amount; i++) {
                numOfWays[i][j] = 0;
                //there is a way to optimise this as the calls seem to repeat between i and (i-k)
                for (int k = 0; k <= i; k += coins[j]) {
                    numOfWays[i][j] += numOfWays[i-k][j-1];
                }
            }
        } 
        // for (int j = 0; j < coins.size(); j++) {
        //     for (int i = 0; i <= amount; i++) {
        //         cout << numOfWays[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return numOfWays[amount][coins.size() - 1];
    } 
};
