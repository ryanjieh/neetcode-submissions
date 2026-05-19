class Solution {
    fun findRedundantConnection(edges: Array<IntArray>): IntArray {
            val graphSize = edges.size
            val componentsTemp = MutableList(graphSize) {it}
            fun findLeader(index: Int): Int {
                if (componentsTemp[index] == index) {
                    return index
                } else {
                    return findLeader(componentsTemp[index])
                }
            }
            for (edge in edges) {
                val zeroLeader = findLeader(edge[0] - 1)
                val oneLeader = findLeader(edge[1] - 1)
                println("${zeroLeader}   ${oneLeader}")
                if (zeroLeader == oneLeader) {
                    return edge
                } else {
                    val smallLeader = min(zeroLeader, oneLeader)
                    val bigLeader = max(zeroLeader, oneLeader)
                    componentsTemp[bigLeader] = smallLeader
                }
            }
            throw IndexOutOfBoundsException("something wrong")
        }
}
