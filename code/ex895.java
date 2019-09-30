class FreqStack {
    public Map<Integer, Stack<Integer>> freq2int;
    public Map<Integer, Integer> int2freq;
    public int maxFreq;

    public FreqStack() {
        freq2int = new HashMap<Integer, Stack<Integer>>();
        int2freq = new HashMap<Integer, Integer>();
        maxFreq = 0;
    }
    
    public void push(int x) {
        // Update int2freq
        int2freq.put(x, int2freq.getOrDefault(x, 0) + 1);
        maxFreq = Math.max(maxFreq, int2freq.get(x));
        
        // Update freq2int
        Stack<Integer> stk = freq2int.getOrDefault(int2freq.get(x), new Stack<Integer>());
        stk.push(x);
        freq2int.put(int2freq.get(x), stk);
    }
    
    public int pop() {
        int out = freq2int.get(maxFreq).pop();
        
        // Update int2freq
        int2freq.put(out, int2freq.get(out) - 1);
        if (int2freq.get(out) == 0)    int2freq.remove(out);
        
        // Update freq2int
        if (freq2int.get(maxFreq).size() == 0)    freq2int.remove(maxFreq--);
        
        return out;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */