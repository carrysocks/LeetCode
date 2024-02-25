/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode b = new ListNode(0);
        ListNode e = new ListNode(0);
        ListNode s = new ListNode(0);
        ArrayList<ListNode> x = new ArrayList<ListNode>();
        reverse(head,m,n,1,b,e,s, x);
        return x.get(0);
    }
    public ListNode reverse(ListNode list, int m, int n, int counter,ListNode b, ListNode e, ListNode s, ArrayList<ListNode> head){
        if(counter == n+1) return list;
        if(counter == m) b = list;
        if(counter == n) e = list;
        if(counter == m-1) s = list;
        if(m == 1 && counter == n && head.size() == 0) head.add(list);
        if(counter == 1 && m != 1 && head.size() == 0) head.add(list);
        ListNode x = reverse(list.next,m, n, counter++, b,e,s,head);
        
        if(counter == n){
            if(s!=null)
                 s.next = list;
            else{
                s = list;
            }
            b.next = x;
        }
       
        if(counter < n && counter >= m){
            x.next = list;
        }
        return list;
    }
}