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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode nPlus1thFromEnd = head;
        ListNode temp = head;
        int size = n;
        for (int i = 0; i < n-1; i++) {
            temp = temp.next;
        }
        if (temp.next == null) {
            return head.next;
            //case where nth from end is start
        } else {
            temp = temp.next;
        }
        while (temp.next != null) {
            temp = temp.next;
            nPlus1thFromEnd = nPlus1thFromEnd.next;
        }
        nPlus1thFromEnd.next = nPlus1thFromEnd.next.next;
        return head;
    }
}
