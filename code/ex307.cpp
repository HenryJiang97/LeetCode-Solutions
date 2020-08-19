struct FenwickTree {
    vector<int> prefix;
    
    FenwickTree(int n) {
        prefix.resize(n + 1);
    }
    
    void update(int idx, int delta) {
        idx++;
        while (idx < prefix.size()) {
            prefix[idx] += delta;
            idx += lowBit(idx);
        }
    }
    
    int query(int idx) {
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += prefix[idx];
            idx -= lowBit(idx);
        }
        return sum;
    }
    
private:
    int lowBit(int x) {
        return x & (-x);
    }
};

class NumArray {
    vector<int> nums;
    FenwickTree* ft;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        ft = new FenwickTree(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ft->update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        ft->update(i, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return ft->query(j) - ft->query(i - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */