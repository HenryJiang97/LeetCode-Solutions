// Multiset

class MedianFinder {
public:
    multiset<int> set;
    multiset<int> :: iterator it;
    int cnt = 0;
    
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        cnt++;
        set.insert(num);
        if (cnt == 1)    it = set.begin();
        else {
            if (cnt % 2 == 1) {  // even number item to odd number item
                if (num >= *it)    it = next(it);
            } else {  // Odd number item to even number item
                if (num < *it)    it = prev(it);
            }
        }
    }
    
    double findMedian() {
        if (cnt % 2 == 1) {
            return (double)(*it);
        } else {
            int n1 = *it;    it = next(it);    int n2 = *it;    it = prev(it);
            return (double)(n1 + n2) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */