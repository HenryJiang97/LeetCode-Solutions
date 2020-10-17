struct SegmentTree {
    SegmentTree* left;
    SegmentTree* right;
    int start, end, status;
    SegmentTree(int s, int e, int st): status(st), start(s), end(e), left(NULL), right(NULL) {}
    
public:
    void setStatus(int i, int j, int s) {
        if (i <= start && j >= end && left == NULL) {    // If the interval is included in [start, end]
            status += s;
            return;
        }
        if (i >= end || j <= start)    return;    // The interval is outside [start, end]
        
        int mid = start + (end - start) / 2;
        if (left == NULL) {    // Create new left node
            left = new SegmentTree(start, mid, status);
            right = new SegmentTree(mid, end, status); 
        }
        
        left->setStatus(i, j, s);
        right->setStatus(i, j, s);
    }
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        SegmentTree* st = new SegmentTree(0, length, 0);
        for (auto& update : updates) {
            st->setStatus(update[0], update[1] + 1, update[2]);
        }
        
        vector<int> res(length);
        dfs(st, res);
        return res;
    }
    
private:
    void dfs(SegmentTree* st, vector<int>& res) {
        if (st->left != NULL) {
            dfs(st->left, res);
            dfs(st->right, res);
            return;
        }
        for (int i = st->start; i < st->end; i++) {
            res[i] = st->status;
        }
    }
};