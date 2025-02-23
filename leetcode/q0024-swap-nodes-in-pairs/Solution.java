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

public class Solution {
    private static ListNode swapPairsDebug(ListNode head) {
        if (head == null) {
            return head;
        }

        ListNode origHead = head.next;        
        
        ListNode curr = head;
        ListNode prev = null;

        while (curr != null) {
            printList(origHead, "swapPairs entry");

            ListNode nextPrev = curr;
            ListNode nextCurr = curr.next.next;

            if (prev != null) {
                prev.printNode("loop prev entry");
            } else {
                System.out.println("loop prev entry: null");
            }
            curr.printNode("loop curr entry");

            ListNode n1 = curr.next;
            n1.printNode("loop n1 entry");

            curr.next = n1.next;
            n1.next = curr;

            if (prev != null) {
                prev.next = n1;
            }

            curr = nextCurr;
            if (curr != null) {
                curr.printNode("loop curr exit");
            }
            prev = nextPrev;
            prev.printNode("loop prev exit");

            printList(origHead, "swapPairs exit");
        }

        return origHead;
    }

    private static ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode newHead = head.next;        
        
        ListNode curr = head;
        ListNode prev = null;

        while (curr != null && curr.next != null) {
            ListNode currNext = curr.next;

            curr.next = currNext.next;
            currNext.next = curr;

            if (prev != null) {
                prev.next = currNext;
            }

            prev = curr;
            curr = curr.next;
        }

        return newHead;
    }

    private static void testSwapPairs(int[] values) {

        ListNode n = new ListNode(values[values.length-1]);
        ListNode h = n;

        for (int i = values.length-2; i >= 0; i--) {
           h = new ListNode(values[i], n);
           n = h; 
        }

        printList(h, "Original List");
        h = swapPairs(h);
        printList(h, "Swapped List");
    }

    private static void printList(ListNode head, String title) {
        System.out.println(title);

        ListNode n = head;
        int i = 1;
        while (n != null) {
            n.printNode(String.format("%d", i));
            n = n.next;
            i++;
        }
    }

    public static void main(String[] args) {
        //int[] values = {1,2,3,4};
        //int[] values = {1,2,3,4,5,6};
        //int[] values = {1,2,3};
        //int[] values = {1,2};
        int[] values = {1};
        testSwapPairs(values);
    }    
}

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }

    public void printNode() {
        printNode("");
    }

    public void printNode(String title) {
        System.out.println(String.format("%s: node %h: %d", title, this, this.val));
    }
}
