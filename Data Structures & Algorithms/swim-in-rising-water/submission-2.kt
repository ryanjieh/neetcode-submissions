import java.util.PriorityQueue
import kotlin.math.min
import kotlin.math.max
class Solution {
        fun swimInWater(grid: Array<IntArray>): Int {
            var maxLevel = grid.size * grid[0].size
            var minLevel = 0
            while (maxLevel != minLevel) {
                println("${maxLevel} ${minLevel}")
                println(searchWithLevel(grid.map{it.copyOf()}.toTypedArray(), 14))
                if (searchWithLevel(grid.map{it.copyOf()}.toTypedArray(), (maxLevel+minLevel)/2)) {
                    maxLevel = (maxLevel+minLevel)/2
                } else {
                    minLevel = (maxLevel+minLevel)/2 + 1
                }
                
            }
            return maxLevel
        }
        fun searchWithLevel(grid: Array<IntArray>, level: Int): Boolean {
            val verIncrements = listOf(1, -1, 0, 0)
            val horIncrements = listOf(0, 0, -1, 1)
            val searchCells: Queue<Pair<Int, Int>> = LinkedList()
            searchCells.add(Pair(0, 0))
            while (searchCells.size > 0) {
                val theFirst = searchCells.peek().first
                val theSecond = searchCells.peek().second
                val currentLevel = grid[theFirst][theSecond]
                if (currentLevel <= level) {
                    grid[theFirst][theSecond] = grid.size * grid.size + 2
                    for (i in 0..3) {
                        if (theFirst+verIncrements[i] >= 0 && theFirst+verIncrements[i] < grid.size
                            && theSecond+horIncrements[i] >= 0 && theSecond+horIncrements[i] < grid.size
                            && grid[theFirst+verIncrements[i]][theSecond+horIncrements[i]] <= level) {
                            searchCells.add(Pair(theFirst + verIncrements[i], theSecond + horIncrements[i]))
                            println(theFirst + verIncrements[i])
                            if (theFirst+verIncrements[i] == grid.size - 1 && theSecond+horIncrements[i] == grid.size - 1) {
                                return true
                            }
                        }
                    }
                }
                searchCells.remove()
            }
            return false
        }
}
