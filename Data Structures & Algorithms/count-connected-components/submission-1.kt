class Solution {
    fun countComponents(n: Int, edges: Array<IntArray>): Int {
            val componentsTemp = MutableList(n) {it}
            fun findLeader(index: Int): Int {
                if (componentsTemp[index] == index) {
                    return index
                } else {
                    return findLeader(componentsTemp[index])
                }
            }
            for (edge in edges) {
                val zeroLeader = findLeader(edge[0])
                val oneLeader = findLeader(edge[1])
                val smallLeader = min(zeroLeader, oneLeader)
                val bigLeader = max(zeroLeader, oneLeader)
                componentsTemp[bigLeader] = smallLeader
            }
            val resultSet = mutableSetOf<Int>()
            for (node in componentsTemp) {
                resultSet.add(findLeader(node))
            }
            return resultSet.size
        }
}
