class MedianFinder {
    int n = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {    // O(log(n / 2))
        if (!minHeap.empty())    maxHeap.push(min(num, minHeap.top()));
        else    maxHeap.push(num);
        if (!maxHeap.empty())    minHeap.push(max(num, maxHeap.top()));
        else    minHeap.push(num);
        
        n++;
        if (maxHeap.size() > (n + 1) / 2) {
            maxHeap.pop();
            minHeap.pop();
        }
    }
    
    double findMedian() {    // O(1)
        return (double)(maxHeap.top() + minHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */