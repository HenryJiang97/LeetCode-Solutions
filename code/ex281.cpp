class ZigzagIterator {
    vector<int> v1, v2;
    int p1, p2, role;
    
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        this->p1 = 0;
        this->p2 = 0;
        this->role = p1 < v1.size() ? 1 : 2;
    }

    int next() {
        int ret = 0;
        if (role == 1) {
            ret = v1[p1++];
            if (p2 < v2.size())    role = 2;
        } else {
            ret = v2[p2++];
            if (p1 < v1.size())    role = 1;
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