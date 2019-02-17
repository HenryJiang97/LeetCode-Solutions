import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

class MedianFinder {
    private static List<Integer> list;
    
    /** initialize your data structure here. */
    public MedianFinder() {
        list = new ArrayList<>();
    }
    
    public void addNum(int num) {
        list.add(num);
        Collections.sort(list);
    }
    
    public double findMedian() {
        double result;
        if (list.size() % 2 == 0)
            result = (double)(list.get(list.size() / 2 - 1) + list.get(list.size() / 2)) / 2;
        else
            result = list.get((list.size() - 1) / 2);
        
        return result;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */