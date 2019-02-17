import java.util.ArrayList;
import java.util.List;

class MyQueue {

    List<Integer> l = new ArrayList<>();
    List<Integer> t = new ArrayList<>();

    /** Initialize your data structure here. */
    public MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        l.add(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        // Save other elements to a new list
        int l_size = l.size();
        for (int i = 0; i < l_size - 1; i++) {
            int temp = l.remove(l.size() - 1);
            t.add(temp);
        }

        // Remove the target element
        int r = l.remove(l.size() - 1);
        
        // Add those elements back to l
        int t_size = t.size();
        for (int i = 0; i < t_size; i++) {
            int temp = t.remove(t.size() - 1);
            l.add(temp);
        }

        return r;
    }
    
    /** Get the front element. */
    public int peek() {
        // Save other elements to a new list
        int l_size = l.size();
        for (int i = 0; i < l_size - 1; i++) {
            int temp = l.remove(l.size() - 1);
            t.add(temp);
        }

        // Get the target element
        int r = l.get(l.size() - 1);
        
        // Add those elements back to l
        int t_size = t.size();
        for (int i = 0; i < t_size; i++) {
            int temp = t.remove(t.size() - 1);
            l.add(temp);
        }

        return r;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return l.size() == 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */