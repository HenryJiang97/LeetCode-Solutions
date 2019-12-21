class MyCircularQueue {
    private int[] queue;
    private int head = 0, tail = 0, k;
    private boolean full = false;
    
    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        this.k = k;
        this.queue = new int[k];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if (full)    return false;
        queue[tail++] = value;
        if (tail == k)    tail = 0;
        if (tail == head)    full = true;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (isEmpty())    return false;
        int ret = queue[head++];
        if (head == k)    head = 0;
        full = false;
        return true;
    }
    
    /** Get the front item from the queue. */
    public int Front() {
        return isEmpty() ? -1 : queue[head];
    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        if (isEmpty())    return -1;
        else    return tail == 0 ? queue[k - 1] : queue[tail - 1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return head == tail && !full;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return full;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */