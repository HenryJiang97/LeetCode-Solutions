class CustomStack {
    private int size;
    private Deque<Integer> dque;
    
    public CustomStack(int maxSize) {
        size = maxSize;
        dque = new LinkedList();
    }
    
    public void push(int x) {
        if (dque.size() < size)    dque.push(x);
    }
    
    public int pop() {
        return dque.isEmpty() ? -1 : dque.pollFirst();
    }
    
    public void increment(int k, int val) {
        Stack<Integer> temp = new Stack<>();
        int queSize = dque.size();
        for (int i = 0; i < Math.min(queSize, k); i++)
            temp.push(dque.pollLast() + val);
        
        while (!temp.isEmpty())
            dque.offer(temp.pop());
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */