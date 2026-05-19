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
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        int counter = 0;
        ArrayList<Integer> numbers = new ArrayList<Integer>();
        while (head != null) {
            numbers.add(0, head.val);
            head = head.next;
            counter++;
        }
        counter--;
        ListNode output = new ListNode(numbers.get(counter));
        counter--;
        while (counter >= 0) {
            ListNode temp = new ListNode(output.val, output.next);
            output.next = temp;
            output.val = numbers.get(counter);
            counter--;
        }
        return output;
    }
}
