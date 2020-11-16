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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        vector<long> prefix{0};
        for (long num : nums)    prefix.push_back(prefix.back() + num);
        
        set<long> set(prefix.begin(), prefix.end());    // Sort and remove duplicated elements
        vector<long> arr(set.begin(), set.end());    // Sorted elements
        
        FenwickTree* ft = new FenwickTree(arr.size());
        int cnt = 0;
        for (int i = 0; i < prefix.size(); i++) {
            long lo = prefix[i] - upper;
            long hi = prefix[i] - lower;
            cnt += ft->query(distance(arr.begin(), --upper_bound(arr.begin(), arr.end(), hi)))
                 - ft->query(distance(arr.begin(), --lower_bound(arr.begin(), arr.end(), lo)));
            ft->add(distance(arr.begin(), lower_bound(arr.begin(), arr.end(), prefix[i])));
        }
        
        return cnt;
    }
};