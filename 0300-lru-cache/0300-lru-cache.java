import java.util.Hashtable;
public class LRUCache {
    class Node{
        int key;
        int value;
        Node prev;
        Node next;
        Node(int key, int val){
            this.key = key;
            this.value = val;
            prev = null;
            next = null;
        };
    }
    private Node head;
    private Node tail;
    private Hashtable<Integer, Node> ht;
    private int len;
    private int capacity;
    public LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-2, -2);
        head.next = tail;
        tail.prev = head;
        ht = new Hashtable();
        this.capacity = capacity;
        this.len = 0;
    }
    
    public int get(int key) {
        if(!ht.containsKey(key)) return -1;
        Node cur = ht.get(key);
        Node pnode = cur.prev;
        Node nnode = cur.next;
        pnode.next = nnode;
        nnode.prev = pnode;
        cur.next = head.next;
        head.next = cur;
        cur.next.prev = cur;
        cur.prev = head;                        
        return cur.value;
    }
    
    public void set(int key, int value) {
        int x = get(key);
        if(x>0) head.next.value = value;
        else{
            Node cur = new Node(key, value);
            ht.put(key, cur);
            cur.next = head.next;
            head.next = cur;
            cur.next.prev = cur;
            cur.prev = head;            
            if(this.len==capacity){
                ht.remove(tail.prev.key);
                tail.prev = tail.prev.prev;
                tail.prev.next = tail;                
            }else this.len++;            
        }
    }
}