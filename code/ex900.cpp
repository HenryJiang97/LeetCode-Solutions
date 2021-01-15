class RLEIterator {
    vector<int> a;
    int p = 0;
public:
    RLEIterator(vector<int>& A) {
        a = A;
    }
    
    int next(int n) {
        while (p < a.size() && n > 0) {
            if (n <= a[p]) {
                int ret = a[p + 1];
                a[p] -= n;
                if (a[p] == 0)    p += 2;
                return ret;
            } else {
                n -= a[p];
                p += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */