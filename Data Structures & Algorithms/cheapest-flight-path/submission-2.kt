import kotlin.Int.Companion.MAX_VALUE
class Solution {
    fun findCheapestPrice(n: Int, flights: Array<IntArray>, src: Int, dst: Int, k: Int): Int {
            var prices = Array<Int>(n) {100001}
            prices[src] = 0
            for (i in 0..k) {
                val tempPrices = prices.copyOf()
                for (flight in flights) {
                    if (tempPrices[flight[1]] > tempPrices[flight[0]] + flight[2] && prices[flight[1]] > tempPrices[flight[0]] + flight[2]) {
                        prices[flight[1]] = tempPrices[flight[0]] + flight[2]
                    }
                }
            }
            if (prices[dst] == 100001) {
                return -1
            } else {
                return prices[dst]
            }
        }
}
