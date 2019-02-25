class MyLinkedList {
    private class Node {
        int val;
        Node next;
        // Init
        public Node(int v) {val = v; next = null;}
    }
    
    private Node head;
    private Node tail;
    
    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        Node p = head; 
        int i = 0;
        while (p != null) {
            if (i == index)    return p.val;
            i++;    p = p.next;
        }    
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        Node n = new Node(val);
        n.next = head;
        head = n;
        // Update tail
        if (head.next == null)    tail = head;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node n = new Node(val);
        tail.next = n;
        tail = n;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        // Add at head
        if (index == 0) {
            Node n = new Node(val);
            n.next = head;
            head = n;
            return;
        }
        
        Node p = head;
        int i = 0;
        while (p != null) {
            if (i == index - 1) {
                Node n = new Node(val);
                n.next = p.next;
                p.next = n;
                // Update tail
                if (n.next == null)    tail = n;
                break;
            }
            i++;    p = p.next;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        // Delete at head
        if (index == 0)    {head = head.next;    return;}
        
        Node p = head;
        int i = 0;
        while (p != null) {
            if (i == index - 1 && p.next != null) {
                p.next = p.next.next;
                // Update tail
                if (p.next == null)    tail = p;
                break;
            }
            i++;    p = p.next;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */