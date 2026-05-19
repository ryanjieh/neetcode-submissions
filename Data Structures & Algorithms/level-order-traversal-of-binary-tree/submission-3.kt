/**
* Definition for a binary tree node.
* class TreeNode(var `val`: Int) {
* var left: TreeNode? = null
* var right: TreeNode? = null
* }
*/

class Solution {
fun levelOrder(root: TreeNode?): List<List<Int>> {
if (root == null) {
return listOf()
}
if (root.right == null && root.left == null) {
return listOf(listOf(root.`val`))
}
if (root.right == null) {
    println("left only")
    return listOf(listOf(root.`val`)) + (levelOrder(root.left!!))
} 
if (root.left == null) {
    println("right only")
return listOf(listOf(root.`val`)) + (levelOrder(root.right!!))
} 
println("both")
val leftLO = levelOrder(root.left!!)
val rightLO = levelOrder(root.right!!)
if (leftLO.size >= rightLO.size) {
    return listOf(listOf(root.`val`)) + leftLO.zip(rightLO) 
        {it1, it2 -> if (it2 == null) it1 else it1 + it2} +
        leftLO.drop(rightLO.size)
} else {
    return listOf(listOf(root.`val`)) + rightLO.zip(leftLO) 
        {it1, it2 -> if (it2 == null) it1 else it2 + it1} +
        rightLO.drop(leftLO.size)
} 

}
}
