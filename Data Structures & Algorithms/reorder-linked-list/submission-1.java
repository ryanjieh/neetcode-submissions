public class Solution {
    public void reorderList(ListNode head) {
        //node counter
        ListNode halfNode = head;
        ListNode endNode = head;
        Boolean doesHalfMove = true;
        while(endNode.next != null){
            endNode = endNode.next;
            if(doesHalfMove){
                halfNode = halfNode.next;
            }
            doesHalfMove = !doesHalfMove;
        }
        //second half list reverse
        ListNode halfPoint = reverseListOptimised(halfNode);
        ListNode startPoint = head;
        while (halfPoint != null){
            ListNode tmp1 = startPoint.next;
            ListNode tmp2 = halfPoint.next;
            startPoint.next = halfPoint;
            if (halfPoint != tmp1) {
                halfPoint.next = tmp1;
            }
            startPoint = tmp1;
            halfPoint = tmp2;
        }
    }

    public ListNode reverseListOptimised(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
}