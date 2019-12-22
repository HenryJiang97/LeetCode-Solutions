class MovingAverage {
    queue<int> que;
    int size, sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0;
    }
    
    double next(int val) {
        if (que.size() >= size) {
            sum -= que.front();
            que.pop();
        }
        sum += val;
        que.push(val);
        return (double)sum / que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */