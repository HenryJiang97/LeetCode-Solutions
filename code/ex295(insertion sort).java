class MedianFinder {
    List<Integer> list;

    /** initialize your data structure here. */
    public MedianFinder() {
        this.list = new ArrayList<>();
    }
    
    public void addNum(int num) {
        if (list.size() == 0)    {list.add(num);    return;} 
        // Binary search for position to insert num
        int idx = binarySearch(num);
        list.add(idx, num);
    }
    
    private int binarySearch(int num) {    // Find the index where the first number is larget or equal to num
        if (num >= list.get(list.size() - 1))    return list.size();
        int lo = 0, hi = list.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (list.get(mid) < num)    lo = mid + 1;
            else    hi = mid;
        }
        return hi;
    }
    
    public double findMedian() {
        return list.size() % 2 == 1 ? (double)list.get((list.size() - 1) / 2) : ((double)list.get(list.size() / 2 - 1) + (double)list.get(list.size() / 2)) / 2;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */