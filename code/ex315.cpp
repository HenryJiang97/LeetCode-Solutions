struct FenwickTree {
    vector<int> prefix;
    FenwickTree(int n) {
        prefix.resize(n + 1);
    }
    
    void add(int i) {
        i++;
        while (i < prefix.size()) {
            prefix[i]++;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += prefix[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        FenwickTree* ft = new FenwickTree(20001);
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            res[i] = ft->query(nums[i] + 10000 - 1);
            ft->add(nums[i] + 10000);
        }
        return res;
    }
};