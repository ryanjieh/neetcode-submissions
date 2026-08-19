class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //let Y(n) be the value of obtaining a coin on day n
        //let H(n) be the value of holding a coin (but not obtaining it on day n itself) on day n 
        //let N(n) be the value of not obtaining a coin on day n
        //Y(n) = -P(n) + H(n+1)
        //H(n) = max(H(n+1), P(n+1) + N(n+2))
        //N(n) = max(Y(n+1), N(n+1))
        int size = prices.size();
        //cout << size << "\n";
        int y = -prices[size - 1];
        int h = prices[size - 1];
        int n = 0;
        int ynew, hnew, nnew;
        for (int i = size - 2; i >= 0; i--) {
            ynew = -prices[i] + h;
            hnew = max(h, prices[i] + n);
            nnew = max(y, n);
            y = ynew;
            h = hnew;
            n = nnew;
            //cout << y << " " << h << " " << n << "\n";
        }
        return max(y, n);
    }
};