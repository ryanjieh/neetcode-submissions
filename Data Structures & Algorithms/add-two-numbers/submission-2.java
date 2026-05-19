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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null || (l1.val == 0 && l1.next == null)) {
            return l2;
        }
        if (l2 == null || (l2.val == 0 && l2.next == null)) {
            return l1;
        }
        ListNode carry = new ListNode(0);
        int sum = l1.val + l2.val;
        if (sum >= 10) {
            sum = sum - 10;
            carry = new ListNode(1);
        }
        return new ListNode(sum, addTwoNumbers(l1.next, addTwoNumbers(carry, l2.next)));
    }
}
