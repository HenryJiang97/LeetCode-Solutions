class Solution {
    int n;
    vector<int> prefix{0};
    vector<int> w;
    
public:
    Solution(vector<int>& W) {
        this->w = W;    this->n = W.size();
        for (int i = 0; i < n; i++)
            prefix.push_back(prefix.back() + W[i]);
    }
    
    int pickIndex() {
        int random = rand() % prefix.back() + 1;
        // Binary search for the index
        int lo = 0, hi = prefix.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (prefix[mid] >= random)    hi = mid;
            else    lo = mid + 1;
        }
        return hi - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */