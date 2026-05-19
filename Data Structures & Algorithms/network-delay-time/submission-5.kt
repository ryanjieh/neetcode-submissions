import java.util.PriorityQueue
import java.util.Collections

class Solution {
    fun networkDelayTime(times: Array<IntArray>, n: Int, k: Int): Int {
        val infinity = 100001
        val shortestPathLength = MutableList(n+1) {infinity}
        val compareNode: Comparator<Int> = Comparator { o1, o2 -> shortestPathLength[o1] - shortestPathLength[o2] }
        val shortestPQ = PriorityQueue<Int>()
        shortestPathLength[k] = 0
        shortestPathLength[0] = 0
        shortestPQ.add(k)
        val adjList = makeAdjList(times, n)
        while (shortestPQ.isNotEmpty()) {
            val target = shortestPQ.poll()
            println(target)
            shortestPQ.remove(target)
            for (i in adjList[target]) {
                if (shortestPathLength[i.first] - shortestPathLength[target] > i.second) {
                    shortestPathLength[i.first] = shortestPathLength[target] + i.second
                    shortestPQ.add(i.first)
                }
            }
            
        }
        val answer = Collections.max(shortestPathLength)
        println(shortestPathLength)
        if (answer == infinity) {return -1}
        else {return answer}
    }
    fun makeAdjList(times: Array<IntArray>, n: Int): MutableList<MutableList<Pair<Int, Int>>> {
        val adjList: MutableList<MutableList<Pair<Int, Int>>> = MutableList(n+1) {mutableListOf()}
        for (edge in times) {
            adjList[edge[0]].add(element = (edge[1] to edge[2]))
        }
        return adjList
    }
}

