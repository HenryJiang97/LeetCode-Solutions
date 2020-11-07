class ZigzagIterator {
    vector<int> v1, v2;
    int arr = 0, p1 = 0, p2 = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;    this->v2 = v2;
        arr = v1.size() == 0 ? 1 : 0;
    }

    int next() {
        int ret;
        if (arr == 0) {
            ret = v1[p1++];
            if (p2 < v2.size())    arr = 1;
        } else {
            ret = v2[p2++];
            if (p1 < v1.size())    arr = 0;
        }
        return ret;
    }

    bool hasNext() {
        return p1 < v1.size() || p2 < v2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */