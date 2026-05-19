/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public int diameterOfBinaryTree (TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftDiam = 0;
        int rightDiam = 0;
        int leftRightDiam = 0;
        if (root.left != null && root.right != null) {
            leftRightDiam = maxDepth(root.left) + maxDepth(root.right); 
        }
        if (root.left != null) {
            leftDiam = Math.max(diameterOfBinaryTree(root.left), maxDepth(root.left));
        }
        if (root.right != null) {
            rightDiam = Math.max(diameterOfBinaryTree(root.right), maxDepth(root.right));
        }
        System.out.println(Math.max(Math.max(leftDiam, rightDiam), leftRightDiam));
        return Math.max(Math.max(leftDiam, rightDiam), leftRightDiam);
    }
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        }
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}
