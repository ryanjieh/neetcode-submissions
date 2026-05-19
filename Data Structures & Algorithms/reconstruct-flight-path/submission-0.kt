class Solution {
        val answer = mutableListOf<String>()
        fun findItinerary(tickets: List<List<String>>): List<String> {
            val airportsList = mutableSetOf<String>()
            for (ticket in tickets) {
                airportsList.add(ticket[0])
                airportsList.add(ticket[1])
            }
            //making adjacency count
            val adjacencyList = airportsList.associateWith{PriorityQueue<String>()}
            for (ticket in tickets) {
                adjacencyList[ticket[0]]!!.add(ticket[1])
            }
            //eulerian path algorithm
            val start = "JFK"
            dfsGreedy(start, adjacencyList)
            return answer.reversed()
        }

        fun dfsGreedy (start: String, adjList: Map<String, PriorityQueue<String>>) {
            while (adjList[start]!!.isNotEmpty()) {
                val checking = adjList[start]!!.peek()
                adjList[start]!!.remove()
                dfsGreedy(checking, adjList)
            }
            answer.add(start)
        }
}
