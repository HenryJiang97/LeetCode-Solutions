class FreqStack {
    Map<Integer, Integer> app;    // Store the appearance of each integer
    Map<Integer, Stack<Integer>> pos;    // Store each integer with same appearance
    int mapp;    // Max appearance
    
    public FreqStack() {
        app = new HashMap<Integer, Integer>();
        pos = new HashMap<Integer, Stack<Integer>>();
        mapp = 0;
    }
    
    public void push(int x) {
        // Update app map and freq
        app.put(x, app.getOrDefault(x, 0) + 1);
        mapp = Math.max(mapp, app.get(x));
        
        // Update pos map by grouping integers with same appearance
        int appearance = app.get(x);
        Stack<Integer> stack = pos.getOrDefault(appearance, new Stack<Integer>());
        stack.push(x);
        pos.put(appearance, stack);
    }
    
    public int pop() {
        int out = pos.get(mapp).pop();
        
        // Update app map
        app.put(out, app.get(out) - 1);
        if (app.get(out) == 0)    app.remove(out);
        
        // Update pos map and mapp
        if (pos.get(mapp).size() == 0)    pos.remove(mapp--);    
        
        return out;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */