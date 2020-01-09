class MedianFinder {
    public PriorityQueue<Integer> lo, hi;

    /** initialize your data structure here. */
    public MedianFinder() {
        this.lo = new PriorityQueue<>(new Comparator<Integer>() {    // Max heap
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });
        this.hi = new PriorityQueue<>();    // Min heap
    }
    
    public void addNum(int num) {
        // Insertion
        if (lo.size() == hi.size())    lo.offer(num);
        else    hi.offer(num);
        
        // Balance
        if (!lo.isEmpty() && !hi.isEmpty() && lo.peek() > hi.peek()) {
            int l = lo.poll(), h = hi.poll();
            lo.offer(h);    hi.offer(l);
        }
    }
    
    public double findMedian() {
        if (lo.size() == hi.size())    return (double)(lo.peek() + hi.peek()) / 2;
        else    return (double)lo.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */