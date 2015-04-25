public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null)
            return null;
        while (head.val == val) {
            if (head.next == null)
                return null;
            head = head.next;
        }
        ListNode cur = head;
        while (cur.next != null) {
            if (cur.next.val == val) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }
        return head;
    }
}
