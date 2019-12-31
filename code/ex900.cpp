class RLEIterator {
    int p, n;
    vector<int> arr;
public:
    RLEIterator(vector<int>& A) {
        p = 0;
        n = A.size();
        arr = A;
    }
    
    int next(int N) {
        while (p < n && N > arr[p]) {
            N -= arr[p];
            p += 2;
        }
        if (p >= n)    return -1;
        arr[p] -= N;
        return arr[p + 1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */