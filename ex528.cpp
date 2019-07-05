class Solution {
    int total = 0;
    vector<int> prefix;
public:
    Solution(vector<int>& w) {
        total = accumulate(w.begin(), w.end(), 0);
        prefix.push_back(0);
        for (int i = 0; i < w.size(); i++) {
            prefix.push_back(prefix.back() + w[i]);
        }
    }
    
    int pickIndex() {
        // Get random from 0 to total - 1
        int random = rand() % total;

        // Binary search for random in prefix
        int n = prefix.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (prefix[mid] == random)    return mid;
            else if (prefix[mid] < random)    lo = mid + 1;
            else {
                if (mid - 1 >= 0 && prefix[mid - 1] > random)   hi = mid - 1;
                else    return mid - 1;
            }
        }
        
        return lo - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// 0-3
// Random:
// 0, 1, 2, 3
    
// prefix:
// 0, 1, 4
    
// 0, 1, 1, 1