class MyStack {
    Queue<Integer> queue;
    int cnt = 0;
    
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.offer(x);
        cnt++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        for (int i = 0; i < cnt - 1; i++)
            queue.offer(queue.poll());
        
        cnt--;
        return queue.poll();
    }
    
    /** Get the top element. */
    public int top() {
        for (int i = 0; i < cnt - 1; i++)
            queue.offer(queue.poll());
        
        int res = queue.poll();
        queue.offer(res);
        return res;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return cnt == 0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */