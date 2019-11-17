class Solution {
    vector<int> starting;    // Save the starting sum value of each element(idx)
    int sum = 0;
public:
    Solution(vector<int>& w) {
        starting.resize(w.size());
        for (int i = 0; i < w.size(); i++) {
            sum += w[i];
            if (i + 1 < w.size())
                starting[i + 1] = sum;
        }
    }
    
    int pickIndex() {
        int random = rand() % sum;
        
        // Binary search
        int lo = 0, hi = starting.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (starting[mid] > random)
                hi = mid - 1;
            else
                if (mid + 1 >= starting.size() || starting[mid + 1] > random)
                    return mid;
                else
                    lo = mid + 1;
        }
        
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */