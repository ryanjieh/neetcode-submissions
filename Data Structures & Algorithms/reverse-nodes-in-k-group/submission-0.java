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
    public ListNode reverseKGroup(ListNode head, int k) {
        //sizing the list
        ListNode current = head;
        int nodeCounter = 0;
        while (current != null) {
            current = current.next;
            nodeCounter++;
        }
        int iterations = nodeCounter / k;
        int remainder = nodeCounter % k;
        //editing pointers
        ListNode answer = new ListNode(0, head);
        ListNode answerPrev = answer;
        ListNode answerEndOfK = answer;
        for (int i = 0; i < iterations; i++) {
            //PRE: answerPrev == answerEndOfK AND answerPrev = ik-th element
            for  (int j = 0; j < k; j++) {
                answerEndOfK = answerEndOfK.next;
            }
            ListNode unprocessed = null;
//            System.out.println(answerEndOfK.val);
//            System.out.println("your mom gay");
            if (answerEndOfK.next != null) {
                unprocessed = answerEndOfK.next;
            }
            answerEndOfK.next = null;
            reverseFirstK(answerPrev.next, answerPrev);
            //System.out.println(answerPrev.val);
            while (answerEndOfK.next != null) {
                answerEndOfK = answerEndOfK.next;
            }
            while (answerPrev.next != null) {
                answerPrev = answerPrev.next;
            }
            //POST: answerPrev == answerEndOfK
//            System.out.println(unprocessed.val);
            answerPrev.next = unprocessed;
        }
        return answer.next;
    }
    public void reverseFirstK(ListNode head, ListNode prev) {
        //PRE: head has length of exactly k
        ListNode tail = null;
        ListNode current = head;
        while (current != null) {
            ListNode temp = current.next;
            current.next = tail;
            tail = current;
            current = temp;
        }
        prev.next = tail;
    }
}
