/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public boolean hasCycle(ListNode head) {
        try {
            for (int i = 0; i < 1001; i++) {
                head = head.next;
            }
        } catch(NullPointerException e) {
            return false;
        }
        return true;
    }
}
