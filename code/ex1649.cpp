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
    
    int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int mod = 1e9 + 7;
        int cost = 0;
        FenwickTree* ft = new FenwickTree(100001);
        for (int in : instructions) {
            cost = (cost + min(ft->query(in - 1), ft->query(100000) - ft->query(in))) % mod;
            ft->add(in);
        }
        return cost;
    }
};