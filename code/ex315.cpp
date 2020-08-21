// Binary indexed tree

struct FenwickTree {
    vector<int> arr;
    
    FenwickTree(int n) {
        arr.resize(n + 1);
    }
    
    void update(int idx, int delta) {
        idx++;
        while (idx < arr.size()) {
            arr[idx] += delta;
            idx += (idx & (-idx));
        }
    }
    
    int query(int idx) {
        int sum = 0;
        idx++;
        while (idx > 0) {
            sum += arr[idx];
            idx -= (idx & (-idx));
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        FenwickTree* ft = new FenwickTree(2 * (int)(1e4));
        
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            res[i] = ft->query(nums[i] + (int)(1e4));
            ft->update(nums[i] + (int)(1e4) + 1, 1);
        }
        
        return res;
    }
};