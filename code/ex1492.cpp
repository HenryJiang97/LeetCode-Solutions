class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0)    factors.push_back(i);
        }
        
        int total = factors.back() * factors.back() == n ? factors.size() * 2 - 1 : factors.size() * 2;
        if (k > total)    return -1;
        return k <= factors.size() ? factors[k - 1] : n / factors[total - k];
    }
};