struct FenwickTree {
    vector<int> prefix;
    
    FenwickTree(int n) {
        prefix.resize(n + 1);
    }
    
    void add(int i, int d) {
        i++;
        while (i < prefix.size()) {
            prefix[i] += d;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        int sum = 0;
        i++;
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
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)    return 0;
        
        set<long> arr(nums.begin(), nums.end());    // Remove duplicates
        vector<long> bkp(arr.begin(), arr.end());    // Sorted nums array
        int cnt = 0;
        FenwickTree* ft = new FenwickTree(bkp.size());
        for (int i = 0; i < n; i++) {
            if (nums[i] * 2l < (long)*arr.rbegin()) {
                cnt += i - ft->query(distance(bkp.begin(), upper_bound(bkp.begin(), bkp.end(), nums[i] * 2l)) - 1);
            }
            ft->add(distance(bkp.begin(), lower_bound(bkp.begin(), bkp.end(), nums[i])), 1);
        }
        
        return cnt;
    }
};