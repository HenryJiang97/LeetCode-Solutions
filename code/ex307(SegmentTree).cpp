struct SegmentTree {
    SegmentTree* left;
    SegmentTree* right;
    int sum;
    int start;
    int end;
    SegmentTree(int s, int e) : sum(0), start(s), end(e), left(NULL), right(NULL) {}
};

class NumArray {
    SegmentTree* root;
public:
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }
    
    SegmentTree* buildTree(vector<int>& nums, int lo, int hi) {
        if (lo > hi)    return NULL;
        SegmentTree* node = new SegmentTree(lo, hi);
        if (lo == hi) {
            node->sum = nums[lo];
            return node;
        }
        node->left = buildTree(nums, lo, lo + (hi - lo) / 2);
        node->right = buildTree(nums, lo + (hi - lo) / 2 + 1, hi);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }
    
    void update(int i, int val) {
        updateTree(root, i, val);
    }
    
    void updateTree(SegmentTree* node, int i, int val) {
        if (i == node->start && node->start == node->end) {
            node->sum = val;
            return;
        }
        int mid = node->start + (node->end - node->start) / 2;
        if (i <= mid)    updateTree(node->left, i, val);
        else    updateTree(node->right, i, val);
        node->sum = node->left->sum + node->right->sum;
    }
    
    int sumRange(int i, int j) {
        return query(root, i, j);
    }
    
    int query(SegmentTree* node, int lo, int hi) {
        if (node->start == lo && node->end == hi)
            return node->sum;
        int mid = node->start + (node->end - node->start) / 2;
        if (hi <= mid)    return query(node->left, lo, hi);
        else if (lo > mid)    return query(node->right, lo, hi);
        else    return query(node->left, lo, mid) + query(node->right, mid + 1, hi);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */