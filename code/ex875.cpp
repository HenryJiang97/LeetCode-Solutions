// Binary Search

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // Binary search K between 1 and max_element(piles)
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (!ifPossible(piles, H, mid))    lo = mid + 1;
            else    hi = mid;
        }
        return hi;
    }
    
private:
    bool ifPossible(vector<int>& piles, int H, int K) {  // O(n)
        int h = 0;
        for (int pile : piles) {
            h += ceil((double)pile / K);
        }
        return h <= H;
    }
};